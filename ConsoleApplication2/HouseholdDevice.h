#ifndef HOUSEHOLD_DEVICE_H
#define HOUSEHOLD_DEVICE_H

#include <string>

class IControllable {
public:
    virtual void control(int temperature) = 0;
    virtual ~IControllable() = default;
};

class HouseholdDevice : public IControllable {
protected:
    std::string brand;
    std::string model;
    double weight;
    int year;
    int power;
    bool isOn;
    int currentMode;

public:
    HouseholdDevice();
    HouseholdDevice(const std::string& brand, const std::string& model,
        double weight, int year, int power);

    virtual ~HouseholdDevice() = default;

    std::string getBrand() const { return brand; }
    std::string getModel() const { return model; }
    double getWeight() const { return weight; }
    int getYear() const { return year; }
    int getPower() const { return power; }
    bool getIsOn() const { return isOn; }
    int getCurrentMode() const { return currentMode; }

    void setBrand(const std::string& brand) { this->brand = brand; }
    void setModel(const std::string& model) { this->model = model; }
    void setWeight(double weight) { this->weight = weight; }
    void setYear(int year) { this->year = year; }
    void setPower(int power) { this->power = power; }

    virtual void turnOn() { isOn = true; }
    virtual void turnOff() { isOn = false; }
    virtual void printInfo() const;
};

#endif