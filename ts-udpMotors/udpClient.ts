import * as dgram from "dgram";

const UDP_PORT: number = 4210;
const SERVER_ADDRESS: string = "localhost"; //192.168.1.100 Cambia esta dirección por la dirección IP de tu Arduino
export class UdpClient{
  private static SOCKET: dgram.Socket = dgram.createSocket("udp4");
  private static sendCallback(error: Error | null) {
    if (error) {
      console.error("Error al enviar el comando:", error);
    } else {
      console.log("Comando enviado exitosamente");
    }
  }

  public static sendCommands(commands: Uint8Array) {
    const message = Buffer.from(commands);
    UdpClient.SOCKET.send(message, UDP_PORT, SERVER_ADDRESS, UdpClient.sendCallback);
  }

  public static close(){
    UdpClient.SOCKET.close();
  }
}
