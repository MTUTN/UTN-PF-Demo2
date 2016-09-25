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
        QString result;

        switch (anEnum)
        {
            case TEENAGE: result = "Adolescente"; break;
            case ADULT: result = "Adulto"; break;
            case OLD: result = "Mayor"; break;
            default: result = "Unknown"; break;
        }

        return result;
    }
};

#endif // AGERANGE
