#pragma once

class identification
{

public:
    identification();
    void init();

private:
    int getAge();
    void calculateWeight(int entryForCalculateAge);

    int userInput;
};