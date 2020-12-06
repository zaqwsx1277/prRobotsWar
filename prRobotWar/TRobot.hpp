#ifndef TROBOT_HPP
#define TROBOT_HPP

#include <QObject>

#include <memory>

namespace robot {

enum typeRobot { trOne, trTwo } ;

/*!
 * \brief The TRobot class Базовый класс для создания разных моделей объектов
 * \author AAL
 */
class TRobot
{
private :
    bool mIsDeleted {false} ;       ///< Признак удаления объекта. Необходим для удаления потока в котором этот объект существует
    uint64_t mId { 0 } ;            ///< Уникальный идентификатор объекта

public:
    TRobot() = default ;
    virtual ~TRobot () = default ;

    bool kill () ;                  // Удаление объекта
    uint64_t getId () { return mId ;} ///<  Получение уникального идентификатора объекта
    std::shared_ptr <TRobot> create (typeRobot) ; // Метод создания объекта для патерна Фабрика
};

}
#endif // TROBOT_HPP
