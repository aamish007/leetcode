class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle=6*minutes;
        double hourAngle=30*(hour+minutes/60.0);
        if(hourAngle==12)hourAngle=0;
        double ang=abs(minAngle-hourAngle);
        return min(ang,360-ang);
    }
};