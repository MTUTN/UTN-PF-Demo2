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
        switch (anEnum)
        {
        case MALE: return "Hombre";
        case FEMALE: return "Mujer";
        }
    }
};

#endif // GENDER

