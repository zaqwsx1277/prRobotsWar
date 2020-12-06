#ifndef TROBOT_HPP
#define TROBOT_HPP

#include <QObject>

#include <memory>

namespace robot {

enum typeRobot { trOne, tpTwo } ;

/*!
 * \brief The TRobot class Базовый класс для создания разных моделей объектов
 * \author AAL
 */
class TRobot
{
private :
    bool mIsDeleted {false} ;       ///< Признак удаления объекта. Необходим для удаления потока в котором этот объект существует

public:
    virtual TRobot() = default ;
    virtual ~TRobot () = default ;

    bool kill () ;                  // Удаление объекта
    std::shared_ptr <TRobot> create (typeRobot) ;       // Метод создания объекта для патерна Фабрика
};

}
#endif // TROBOT_HPP
