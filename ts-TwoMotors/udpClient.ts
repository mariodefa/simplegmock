import * as dgram from 'dgram';
import { Command1 } from './Command1';
import { Utils } from './Utils';
import { Direction } from './Direction';

const UDP_PORT = 4210;
const SERVER_ADDRESS = '192.168.1.100'; // Cambia esta dirección por la dirección IP de tu Arduino

const client = dgram.createSocket('udp4');

function sendCommand(commands: Uint8Array) {
    const message = Buffer.from(commands);
    client.send(message, UDP_PORT, SERVER_ADDRESS, (error) => {
        if (error) {
            console.error('Error al enviar el comando:', error);
        } else {
            console.log('Comando enviado exitosamente');
        }
    });
}

async function delay(ms:number):Promise<void>{
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function main():Promise<void>{
    let commands : Uint8Array = new Uint8Array(4);
    let command1 : Command1 = new Command1({pwm:255,direction:Direction.backward});
    let command2 : Command1 = new Command1({pwm:100,direction:Direction.forward});
    commands = Utils.concatByteArrays(command1.getData(),command2.getData());
    sendCommand(commands);    
    await delay(1000);
    let command3: Command1 = new Command1({pwm:0,direction:Direction.backward});
    let command4: Command1 = new Command1({pwm:0,direction:Direction.forward});
    commands = Utils.concatByteArrays(command3.getData(),command4.getData());
    sendCommand(commands);
}

main();

setTimeout(() => {
    client.close();
}, 5000);
