#ifndef GENDER
#define GENDER

#include <QString>

class Gender{
public:
    enum Type{
        MALE,
        FEMALE
    };

    static Type getGenderTypeFromString(QString gender){
        if(gender == "MALE" || gender == "Male" || gender == "male"){
            return MALE;
        }
        if(gender == "FEMALE" || gender == "Female" || gender == "female"){
            return FEMALE;
        }
        throw "Bad gender";
    }

    static QString getStringFromEnum(Type anEnum)
    {
        QString result;

        switch (anEnum)
        {
            case MALE: result = "Hombre"; break;
            case FEMALE: result =  "Mujer"; break;
            default: result = "Unknown"; break;
        }

        return result;
    }
};

#endif // GENDER

