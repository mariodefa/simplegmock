export class Command1{
    private pwm : number;
    private direction : Direction;
    constructor(obj:any){
        this.pwm = obj.pwm;
        this.direction = obj.direction;
    }
    public getData():Uint8Array{
        const pwmByte : number = this.pwm & 0xFF;
        const directionByte : number = Number(this.direction) & 0xFF;
        return new Uint8Array([pwmByte, directionByte]);
    }
}