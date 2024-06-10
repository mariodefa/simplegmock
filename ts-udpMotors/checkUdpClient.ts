import { Command1 } from "./Command1";
import { Utils } from "./Utils";
import { Direction } from "./Direction";
import { UdpClient } from "./udpClient";

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
  UdpClient.sendCommands(commands);
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
  UdpClient.sendCommands(commands);
}

main();

setTimeout(() => {
  UdpClient.close();
}, 5000);