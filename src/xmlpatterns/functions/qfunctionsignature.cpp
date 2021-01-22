/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
****************************************************************************/

#include "qxmlname.h"

#include "qfunctionsignature_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

FunctionSignature::FunctionSignature(const QXmlName nameP,
                                     const Arity minArgs,
                                     const Arity maxArgs,
                                     const SequenceType::Ptr &returnTypeP,
                                     const Expression::Properties props,
                                     const Expression::ID idP) : CallTargetDescription(nameP)
                                                               , m_minArgs(minArgs)
                                                               , m_maxArgs(maxArgs)
                                                               , m_returnType(returnTypeP)
                                                               , m_arguments()
                                                               , m_props(props)
                                                               , m_id(idP)
{
    Q_ASSERT(minArgs <= maxArgs || maxArgs == FunctionSignature::UnlimitedArity);
    Q_ASSERT(m_maxArgs >= -1);
    Q_ASSERT(returnTypeP);
}

void FunctionSignature::appendArgument(const QXmlName::LocalNameCode nameP,
                                       const SequenceType::Ptr &type)
{
    Q_ASSERT(type);

    m_arguments.append(FunctionArgument::Ptr(new FunctionArgument(QXmlName(StandardNamespaces::empty, nameP), type)));
}

QString FunctionSignature::displayName(const NamePool::Ptr &np) const
{
    QString result;
    result += np->displayName(name());
    result += QLatin1Char('(');

    FunctionArgument::List::const_iterator it(m_arguments.constBegin());
    const FunctionArgument::List::const_iterator end(m_arguments.constEnd());

    if(it != end)
    {
        while(true)
        {
            result += QLatin1Char('$');
            result += np->displayName((*it)->name());
            result += QLatin1String(" as ");
            result += (*it)->type()->displayName(np);

            ++it;
            if(it == end)
                break;

            result += QLatin1String(", ");
        }
    }

    if(m_maxArgs == FunctionSignature::UnlimitedArity)
        result += QLatin1String(", ...");

    result += QLatin1String(") as ");
    result += m_returnType->displayName(np);

    return result;
}

bool FunctionSignature::operator==(const FunctionSignature &other) const
{
    return name() == other.name() &&
           isArityValid(other.maximumArguments()) &&
           isArityValid(other.minimumArguments());
}

void FunctionSignature::setArguments(const FunctionArgument::List &args)
{
    m_arguments = args;
}

FunctionArgument::List FunctionSignature::arguments() const
{
    return m_arguments;
}

bool FunctionSignature::isArityValid(const xsInteger arity) const
{
    return arity >= m_minArgs && arity <= m_maxArgs;
}

FunctionSignature::Arity FunctionSignature::minimumArguments() const
{
    return m_minArgs;
}

FunctionSignature::Arity FunctionSignature::maximumArguments() const
{
    return m_maxArgs;
}

SequenceType::Ptr FunctionSignature::returnType() const
{
    return m_returnType;
}

Expression::Properties FunctionSignature::properties() const
{
    return m_props;
}

Expression::ID FunctionSignature::id() const
{
    return m_id;
}

QT_END_NAMESPACE
