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

#ifndef Patternist_XsdModelGroup_H
#define Patternist_XsdModelGroup_H

#include <private/qxsdparticle_p.h>
#include <private/qxsdterm_p.h>

QT_BEGIN_NAMESPACE

template<typename N> class QList;

namespace QPatternist
{
    /**
     * @short Represents a XSD model group object.
     *
     * This class represents the <em>model group</em> object of a XML schema as described
     * <a href="http://www.w3.org/TR/xmlschema11-1/#cModel_Group_Definitions">here</a>.
     *
     * It contains information from either a <em>sequence</em> object, a <em>choice</em> object or an
     * <em>all</em> object.
     *
     * @see <a href="http://www.w3.org/Submission/2004/SUBM-xmlschema-api-20040309/xml-schema-api.html#Interface-XSModelGroup">XML Schema API reference</a>
     * @ingroup Patternist_schema
     * @author Tobias Koenig <tobias.koenig@nokia.com>
     */
    class XsdModelGroup : public XsdTerm
    {
        public:
            typedef QExplicitlySharedDataPointer<XsdModelGroup> Ptr;
            typedef QList<XsdModelGroup::Ptr> List;

            /**
             * Describes the <a href="http://www.w3.org/TR/xmlschema11-1/#mg-compositor">compositor</a> of the model group.
             */
            enum ModelCompositor
            {
                SequenceCompositor,     ///< The model group is a sequence.
                ChoiceCompositor,       ///< The model group is a choice.
                AllCompositor           ///< The model group contains elements only.
            };

            /**
             * Creates a new model group object.
             */
            XsdModelGroup();

            /**
             * Returns always @c true, used to avoid dynamic casts.
             */
            virtual bool isModelGroup() const;

            /**
             * Sets the @p compositor of the model group.
             *
             * @see ModelCompositor
             */
            void setCompositor(ModelCompositor compositor);

            /**
             * Returns the compositor of the model group.
             */
            ModelCompositor compositor() const;

            /**
             * Sets the list of @p particles of the model group.
             *
             * @see <a href="http://www.w3.org/TR/xmlschema11-1/#mg-particles">Particles Definition</a>
             */
            void setParticles(const XsdParticle::List &particles);

            /**
             * Returns the list of particles of the model group.
             */
            XsdParticle::List particles() const;

        private:
            ModelCompositor   m_compositor;
            XsdParticle::List m_particles;
    };
}

QT_END_NAMESPACE

#endif
