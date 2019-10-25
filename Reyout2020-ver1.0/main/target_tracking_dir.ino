float target_tracking_dir(float main_X, float main_Y, float sub_X, float sub_Y)
{
    float a = 28.59776;
    float b = 1.41069;
    float c = -0.86659;
    float d = -0.00139;
    float e = -0.00138;
    float f = 0.00578;
    float main_distance = sqrt(main_X * main_X + main_Y * main_Y);
    float dir = atan2(main_X + sub_X, main_Y + sub_Y);
    float move_dir = a + (b * main_distance) + (c * dir) + (d * main_distance * main_distance) + (e * main_distance * dir) + (f * dir * dir);
    return move_dir;
}