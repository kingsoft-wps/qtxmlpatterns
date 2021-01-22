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

#ifndef Patternist_TemplateParameterReference_H
#define Patternist_TemplateParameterReference_H

#include <private/qvariabledeclaration_p.h>
#include <private/qemptycontainer_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A reference to a template parameter declared with @c xsl:param.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     * @since 4.5
     */
    class TemplateParameterReference : public EmptyContainer
    {
    public:
        TemplateParameterReference(const VariableDeclaration *varDecl);

        virtual bool evaluateEBV(const DynamicContext::Ptr &context) const;
        virtual Item evaluateSingleton(const DynamicContext::Ptr &context) const;
        virtual Item::Iterator::Ptr evaluateSequence(const DynamicContext::Ptr &context) const;

        virtual SequenceType::Ptr staticType() const;
        virtual ExpressionVisitorResult::Ptr accept(const ExpressionVisitor::Ptr &visitor) const;
        virtual Properties properties() const;

        inline const Expression::Ptr &sourceExpression() const;
        inline const VariableDeclaration *variableDeclaration() const;

    private:
        const VariableDeclaration *m_varDecl;
    };

    inline const Expression::Ptr &TemplateParameterReference::sourceExpression() const
    {
        return m_varDecl->expression();
    }

    inline const VariableDeclaration *TemplateParameterReference::variableDeclaration() const
    {
        return m_varDecl;
    }

}

QT_END_NAMESPACE

#endif
