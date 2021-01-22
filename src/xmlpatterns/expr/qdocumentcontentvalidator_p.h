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

#ifndef Patternist_DocumentContentValidator_H
#define Patternist_DocumentContentValidator_H

#include <private/qdynamiccontext_p.h>
#include <private/qexpression_p.h>
#include "qabstractxmlreceiver.h"

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Receives QAbstractXmlReceiver events and validates that they are correct,
     * before sending them on to a second QAbstractXmlReceiver.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     * @todo Escape data
     */
    class DocumentContentValidator : public QAbstractXmlReceiver
    {
    public:
        /**
         * DocumentContentValidator does not own @p receiver.
         */
        DocumentContentValidator(QAbstractXmlReceiver *const receiver,
                                 const DynamicContext::Ptr &context,
                                 const Expression::ConstPtr &expr);

        virtual void namespaceBinding(const QXmlName &nb);
        virtual void characters(const QStringRef &value);
        virtual void comment(const QString &value);

        virtual void startElement(const QXmlName &name);

        virtual void endElement();

        virtual void attribute(const QXmlName &name,
                               const QStringRef &value);

        virtual void processingInstruction(const QXmlName &name,
                                           const QString &value);

        virtual void item(const Item &item);

        virtual void startDocument();
        virtual void endDocument();
        virtual void atomicValue(const QVariant &value);
        virtual void startOfSequence();
        virtual void endOfSequence();

    private:
        QAbstractXmlReceiver *const      m_receiver;
        const DynamicContext::Ptr       m_context;
        const Expression::ConstPtr      m_expr;
        xsInteger                       m_elementDepth;
    };
}

QT_END_NAMESPACE

#endif
