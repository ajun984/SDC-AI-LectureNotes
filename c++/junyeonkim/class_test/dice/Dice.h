//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_DICE_H
#define CLASS_TEST_DICE_H


class Dice {
private:        // 사적인 접근제한         객체 안에 있는 내용을 나만 볼 수 있다
    const int DICE_MAX = 6;
    const int DICE_MIN = 1;
    int diceNumber;

public:         // 공적인 접근제한
    // init_xxx_object
//    Dice() {
//        std::cout << "마! 내가 생성자다!" <<std:: endl;
//    }
    // free
//    ~Dice() {
//        std::cout << "난 뒤질 때 출력됨" << std::endl;
//    }
    Dice();
    void rollDice();
    int getDiceNumber();
    ~Dice();
};
#endif //CLASS_TEST_DICE_H
