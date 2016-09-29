#ifndef AGERANGE
#define AGERANGE

#include <QString>

class Age{
public:
    enum Range{
        TEENAGE,
        YOUNG_ADULT,
        ADULT,
        OLD
    };
    static Range getRangeFromAge(int age){
        if(age<=24){
            return TEENAGE;
        }
        if(age<=43){
            return YOUNG_ADULT;
        }
        if(age<=70){
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
            case YOUNG_ADULT: result = "Adulto Joven"; break;
            case ADULT: result = "Adulto"; break;
            case OLD: result = "Mayor"; break;
            default: result = "Unknown"; break;
        }

        return result;
    }
};

#endif // AGERANGE
