#include "TRobot.hpp"

namespace robot {

//----------------------------------------------------------
/*!
 * \brief TRobot::kill Удаление робота.
 * \return Признак успешности удаления
 */
bool TRobot::kill ()
{
    bool retVal { false } ;

    if (!mIsDeleted) {
        mIsDeleted = true ;
        retVal = true ;
    }

    return retVal ;
}
//----------------------------------------------------------
/*!
 * \brief create Создание объекта для патерна Фабрика
 * \param inTypeRobot Заранее известный тип создаваемого объекта
 * \return Указатель на созданный объект
 */
std::shared_ptr <TRobot> create (typeRobot inTypeRobot)
{
    std::shared_ptr <TRobot> retVal { nullptr} ;

    switch (inTypeRobot) {
      case trOne:

      break;

      case trTwo:

      break;

      default:
      break;
    }

    return retVal ;
}
//-----------------------------------------------------------
}
