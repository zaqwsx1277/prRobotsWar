#ifndef TCOMMON_HPP
#define TCOMMON_HPP

/*!
 * \file Общие объявления для всего проекта
 * \todo Нужно переделать на singleton
 */

#include <mutex>
#include <atomic>
#include <unordered_set>
#include <assert.h>

#include "TRobot.hpp"

namespace common {

//-----------------------------------------------------------------------------
/**
 * @brief The MakeHash struct - Структура, реализующая оператор взятия хеша от контакта
 */
struct dataMakeHash
{
    /**
     * @brief operator () - Оператор сравнения объектов
     * @param inPrtObject - Указатель на объект
     * @return Вернёт результат хеш функции сравнения
     */
    std::size_t operator() (const std::shared_ptr<robot::TRobot>& inPrtObject) const noexcept
    {
        assert(inPrtObject != nullptr);
        return std::hash<robot::TRobot>()( inPrtObject -> getId() );
    }
};
//------------------------------------------------------------------------------
/**
 * @brief The objectCheckEqual struct - Структура, реализующая оператор сравнения объектов
 */
struct objectCheckEqual
{
    bool operator()(const std::shared_ptr<robot::TRobot>& inLeft, const std::shared_ptr<robot::TRobot>& inRight) const noexcept
    {
        assert((inLeft != nullptr) && (inRight != nullptr)) ;
        return inLeft -> getId() == inRight -> getId() ;
    }
};
//-------------------------------------------------------------------------------
static std::mutex stMutexModelRefresh ;         ///< mutex для блокировки доступа к модели при обновлении
static std::mutex stMutexData ;                 ///< mutex для блокировки доступа к контейнеру с данными

const uint32_t stThreadsMax {100} ;             ///< Максимальное количество потоков для создаваемых объектов
static std::mutex stMutexId ;                   ///< mutex для блокировки доступа к контейнеру с данными
 static std::atomic <uint64_t> stId ;           ///< Уникальный идентификатор обекта. При превышении разрядной сетки полетим по exception

static std::unordered_set<robot::TRobot> stData; ///< Конетейнер с данными по объектам
}

#endif // TCOMMON_HPP
