// 设计停车系统
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        sumOfBig = big;
        sumOfMedium = medium;
        sumOfSmall = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1) return --sumOfBig >= 0;
        else if (carType == 2) return --sumOfMedium >= 0;
        else if (carType == 3) return --sumOfSmall >= 0;
        return false;
    }
private:
    int sumOfBig;
    int sumOfMedium;
    int sumOfSmall;
};