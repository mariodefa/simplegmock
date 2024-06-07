import * as dgram from "dgram";
import { Command1 } from "./Command1";
import { Utils } from "./Utils";
import { Direction } from "./Direction";

const UDP_PORT: number = 4210;
const SERVER_ADDRESS: string = "localhost"; //192.168.1.100 Cambia esta dirección por la dirección IP de tu Arduino

const client: dgram.Socket = dgram.createSocket("udp4");

function sendCallback(error: Error | null) {
  if (error) {
    console.error("Error al enviar el comando:", error);
  } else {
    console.log("Comando enviado exitosamente");
  }
}

function sendCommands(commands: Uint8Array) {
  const message = Buffer.from(commands);
  client.send(message, UDP_PORT, SERVER_ADDRESS, sendCallback);
}

async function delay(ms: number): Promise<void> {
  return new Promise((resolve) => setTimeout(resolve, ms));
}

async function main(): Promise<void> {
  let commands: Uint8Array = new Uint8Array(4);
  let command1: Command1 = new Command1({
    pwm: 255,
    direction: Direction.backward,
  });
  let command2: Command1 = new Command1({
    pwm: 100,
    direction: Direction.forward,
  });
  let command3: Command1 = new Command1({
    pwm: 127,
    direction: Direction.backward,
  });
  let command4: Command1 = new Command1({
    pwm: 50,
    direction: Direction.forward,
  });
  commands = Utils.concatByteArrays(
    command1.getData(),
    command2.getData(),
    command3.getData(),
    command4.getData()
  );
  sendCommands(commands);
  await delay(1000);
  let command5: Command1 = new Command1({
    pwm: 0,
    direction: Direction.backward,
  });
  let command6: Command1 = new Command1({
    pwm: 0,
    direction: Direction.forward,
  });
  let command7: Command1 = new Command1({
    pwm: 0,
    direction: Direction.backward,
  });
  let command8: Command1 = new Command1({
    pwm: 0,
    direction: Direction.forward,
  });
  commands = Utils.concatByteArrays(
    command5.getData(),
    command6.getData(),
    command7.getData(),
    command8.getData()
  );
  sendCommands(commands);
}

main();

setTimeout(() => {
  client.close();
}, 5000);
