#include <kipr/wombat.h>

int main()
{
    int servoposone = get_servo_position(0);
    int servopostwo = get_servo_position(1);
    int servoposthree = get_servo_position(2);
    int bruh = servoposone + 50;
    int bruhtwo = servopostwo + 50;
    int bruhthree = servoposthree + 50;
    enable_servo(0);
    enable_servo(1);
    enable_servo(2);
    set_servo_position(0, bruh);
    set_servo_position(1, bruhtwo);
    set_servo_position(2, bruhthree);
    return 0;
}
