#include <kipr/wombat.h>
//Max Value Down For Claw Arm Is 1040
void clawArm(x){
    enable_servo(0);
	set_servo_position(0, x);
    wait_for_milliseconds(1000);
}
//Max Value For Claw Hand Is 1000
void clawHand(x){
	enable_servo(1);
    set_servo_position(1, x);
    wait_for_milliseconds(1000);
}
void forward(x) {
    motor(0, 100);
    motor(1, -95);
    wait_for_milliseconds(x);
    ao();
}
//To turn 90 degrees, make x value 490
void turnLeft(x) {
    motor(0, 100);
    motor(1, 100);
    wait_for_milliseconds(x);
    ao();
}
void turnRight(x) {
    motor(0, -100);
    motor(1, -100);
    wait_for_milliseconds(x);
    ao();
}
void backward(x) {
    motor(0, -100);
    motor(1, 100);
    wait_for_milliseconds(x);
    ao();
}

void lookForBlack(){
    while(analog(0) >= 3800){
            forward(1);
        }
}

void buttonPressed(){
	if(digital(1) == 1){
    	backward(200);
        turnLeft(490);
	}
}
void lookLeftRight(){
    while(digital(1) == 0){
        lookForBlack();
        buttonPressed();
        turnLeft(100);
        lookForBlack();
        buttonPressed();
        turnRight(100);
        lookForBlack();
        buttonPressed();
        turnRight(100);
        lookForBlack();
        buttonPressed();
        turnLeft(100);
        forward(100);
	}
}

void moveRamp(d){
    cmpc(0);
    while(gmpc(0) < d){
        lookForBlack();
        turnLeft(100);
        lookForBlack();
        turnRight(100);
        lookForBlack();
        turnRight(100);
        lookForBlack();
        turnLeft(100);
        forward(50);
    }
    ao();
}

void centerOnColor(a){
    int x;
    int y;
    int stop = 0;
	camera_open();
    while(stop == 0){
        camera_update();
        if(get_object_count(a) > 0){
            printf("I see it. \n");
            x = get_object_center_x(a, 0);
            printf("The center position of object should be(%d)", x);
            if(get_object_center_x(a, 0) < 123){
                turnLeft(3);
            }else if(get_object_center_x(a, 0) > 133){
                turnRight(3);
            }else{
                stop = 1;
                ao();
                if(get_object_count(a) > 0){
                    x = get_object_center_x(a, 0);
                    y = get_object_center_y(a, 0);
                    printf("The center of the object is (%d, %d). \n", x, y);
                }
            }
        }
    }
}
int main() {
    //reset claws to 0
    clawHand(0);
    clawArm(0);
	centerOnColor(0);
    clawArm(900);
    clawHand(320);
    
    

    /*
    lookLeftRight();
    moveRamp(2800);
    */
    return 0;
}
