#include "TRobot.hpp"

#include "TRobotType1.hpp"
#include "TRobotType2.hpp"

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
        retVal = std::make_shared <robot::TRobotType1> () ;
      break;

      case trTwo:
        retVal = std::make_shared <robot::TRobotType2> () ;
      break;

      default:
      break;
    }

    return retVal ;
}
//-----------------------------------------------------------
}
