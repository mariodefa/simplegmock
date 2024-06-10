import { Constants } from './Constants';
import {PadCoordenates} from './PadCoordenates';
import { Command1 } from "./Command1";
import { Utils } from './Utils';
import { Direction } from './Direction';
var GameController = require('gamecontroller');

const N_COMMANDS = 4;//6 to include 2 servos

export class GamePadListener{
    private static gc : any;
    private static servo1Angle : number;
    private static servo2Angle : number;
    private static commands : Command1[];
    private static caterpillar : boolean; //if false control arm
    public static initialize(){
        GamePadListener.servo1Angle = 90;
        GamePadListener.servo2Angle = 90;
        let cmd : any = {pwm: 0, direction: Direction.forward};
        GamePadListener.commands = Array.from({length:N_COMMANDS}).map(x=>new Command1(cmd));//all forward
        GamePadListener.caterpillar = true; //by default move traction control
    }
    public static connectGamePad(){
        //vid 0x044F => 0d 1103
        //pid 0xD007 => 0d 53255
        GamePadListener.gc = new GameController('thrustmaster');
        GamePadListener.gc.connect();
    }
    private static updateCommands(o: any, inputIndex: number){
        let c : PadCoordenates = new PadCoordenates(o);
        let y : number = c.getY();
        let dir : Direction = Direction.forward;
        if(y<128){
            dir=Direction.backward;
            y = 127 - y;
        }else{
            y -= 128;
        }
        if(y>0 && y<Constants.MIN_SPEED_MOTOR){
            y = Constants.MIN_SPEED_MOTOR;
        }
        let vel : number = Utils.mathMap(y,0,127,0,255);
        switch(GamePadListener.caterpillar){
            case true: 
                GamePadListener.commands[inputIndex] = new Command1({pwm: vel, direction: dir});
            break;
            case false: 
                GamePadListener.commands[inputIndex+2] = new Command1({pwm: vel, direction: dir});
            break;
        }
    }
    public static setupCommandsListener(){
        GamePadListener.gc.on('JOYR:move', function(o:any) {
            GamePadListener.updateCommands(o,0);
          });
          GamePadListener.gc.on('JOYL:move', function(o:any) {
            GamePadListener.updateCommands(o,1);       
          });
          GamePadListener.gc.on('X:press', function() {//swap control part, from caterpillar to arm and reverse
            GamePadListener.caterpillar = !GamePadListener.caterpillar;
        });
          
        GamePadListener.gc.on('R1:press', function() {
            GamePadListener.servo1Angle = 180;
            //GamePadListener.commands[4]=new Command1({pwm: GamePadListener.servo1Angle, direction: Direction.forward});
        });
        GamePadListener.gc.on('L1:press', function() {
            GamePadListener.servo1Angle = 0;
            //GamePadListener.commands[4]=new Command1({pwm: GamePadListener.servo1Angle, direction: Direction.forward});
        });
        GamePadListener.gc.on('R2:press', function() {
            GamePadListener.servo2Angle = 180;
            //GamePadListener.commands[5]=new Command1({pwm: GamePadListener.servo2Angle, direction: Direction.forward});
        });
        GamePadListener.gc.on('L2:press', function() {
            GamePadListener.servo2Angle = 0;
            //GamePadListener.commands[5]=new Command1({pwm: GamePadListener.servo2Angle, direction: Direction.forward});
        });
        GamePadListener.gc.on('T:press', function() {
            GamePadListener.servo1Angle = 90;
            //GamePadListener.commands[4]=new Command1({pwm: GamePadListener.servo1Angle, direction: Direction.forward});
        });
        GamePadListener.gc.on('O:press', function() {
            GamePadListener.servo2Angle = 90;
            //GamePadListener.commands[5]=new Command1({pwm: GamePadListener.servo2Angle, direction: Direction.forward});
        });
    }
    public static getCommands(): Command1[]{
        return this.commands;
    }
}