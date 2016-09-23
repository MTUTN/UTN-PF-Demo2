#ifndef AGERANGE
#define AGERANGE

#include <QString>

class Age{
public:
    enum Range{
        TEENAGE,
        ADULT,
        OLD
    };
    static Range getRangeFromAge(int age){
        if(age<=15){
            return TEENAGE;
        }
        if(age< 80){
            return ADULT;
        }
        return OLD;
    }
    static QString getStringFromEnum(Range anEnum)
    {
        switch (anEnum)
        {
        case TEENAGE: return "Adolescente"; break;
        case ADULT: return "Adulto"; break;
        case OLD: return "Mayor"; break;
        }
    }
};

#endif // AGERANGE
