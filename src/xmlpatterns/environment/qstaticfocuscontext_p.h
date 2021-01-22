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

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef Patternist_StaticFocusContext_H
#define Patternist_StaticFocusContext_H

#include <private/qdelegatingstaticcontext_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A StaticContext that carries a specified static type
     * for the context item, but otherwise delegates to another StaticContext.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class Q_AUTOTEST_EXPORT StaticFocusContext : public DelegatingStaticContext
    {
    public:
        /**
         * @p contextItemType may be @c null.
         */
        StaticFocusContext(const ItemType::Ptr &contextItemType,
                           const StaticContext::Ptr &context);
        /**
         * @returns the type passed in the constructor.
         */
        virtual ItemType::Ptr contextItemType() const;

    private:
        const ItemType::Ptr         m_contextItemType;
    };
}

QT_END_NAMESPACE

#endif
