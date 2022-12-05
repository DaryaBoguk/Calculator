#include"functions.h"

void Console::Choose() {
   std::cout << "Choose type of calculator:\n" << "1.Standart,\n" << "2.Engineer,\n" << "3.Programmer,\n" << "4.Data Calculator;\n";
}

void Console::Standart1() {
    std::cout << "Input exit to stop" << std::endl
        << "Functions: +,-,*,/,%,^, , ,s, ~(1/x),C" << std::endl;
    Standart one(other1());
    one.standart();
}

void Console::Engineer1() {
    std::cout << "Input exit to stop\n" <<
        "Functions:\n " <<
        "Sum: a+b;\n" <<
        "Sub: a-b;\n" <<
        "Mult: a*b;\n" <<
        "Division: a/b;\n" <<
        "Pows: a^b;\n" <<
        "Sqrt: aSqrtb;\n" <<
        "Mod: amodb;\n" <<
        "Factorial: a!;\n" <<
        "ln:\n" <<
        "Trigonometry: rad for radian and deg for degree\n" <<
        "Sin: sinrad or sindeg;\n" <<
        "Cos: cosrad or cosdeg;\n" <<
        "Tan: tanrad or tandeg;\n" <<
        "Cot: cotrad or cotdeg;\n" <<
        "Sec:\n" << "Csc:\n" <<
        "Hyp Trigonometry:\t" << "Sh:\t" << "Ch:\t" << "Th:\t" << "Cth:\t";
    Engineer one(other1());
    one.engineer();
}

void Console::ChooseCalculator() {
    int num;
    bool cool = true;
    while (cool) {
        std::cout << "Input number: ";
        std::cin >> num;
        cool = notClearSt();
    }
    switch (num) {
    case(1): Standart1();
        break;
    case(2): Engineer1();
        break;
    //case(3): Programmer();
       // break;
    
    //case(4): Data();
        //break;
    }
}


