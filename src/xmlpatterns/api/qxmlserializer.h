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

#ifndef QXMLSERIALIZER_H
#define QXMLSERIALIZER_H

#include <QtXmlPatterns/QAbstractXmlReceiver>

QT_BEGIN_NAMESPACE


class QIODevice;
class QTextCodec;
class QXmlQuery;
class QXmlSerializerPrivate;

class Q_XMLPATTERNS_EXPORT QXmlSerializer : public QAbstractXmlReceiver
{
public:
    QXmlSerializer(const QXmlQuery &query,
                   QIODevice *outputDevice);

    void namespaceBinding(const QXmlName &nb) override;

    void characters(const QStringRef &value) override;
    void comment(const QString &value) override;

    void startElement(const QXmlName &name) override;

    void endElement() override;

    void attribute(const QXmlName &name,
                   const QStringRef &value) override;

    void processingInstruction(const QXmlName &name,
                               const QString &value) override;

    void atomicValue(const QVariant &value) override;

    void startDocument() override;
    void endDocument() override;
    void startOfSequence() override;
    void endOfSequence() override;

    QIODevice *outputDevice() const;

    void setCodec(const QTextCodec *codec);
    const QTextCodec *codec() const;

    /* The members below are internal, not part of the public API, and
     * unsupported. Using them leads to undefined behavior. */
    void item(const QPatternist::Item &item) override;
protected:
    QXmlSerializer(QAbstractXmlReceiverPrivate *d);

private:
    inline bool isBindingInScope(const QXmlName nb) const;

    /**
     * Where in the document the QXmlSerializer is currently working.
     */
    enum State
    {
        /**
         * Before the document element. This is the XML prolog where the
         * XML declaration, and possibly comments and processing
         * instructions are found.
         */
        BeforeDocumentElement,

        /**
         * This is inside the document element, at any level.
         */
        InsideDocumentElement
    };

    /**
     * If the current state is neither BeforeDocumentElement or
     * AfterDocumentElement.
     */
    inline bool atDocumentRoot() const;

    /**
     * Closes any open element start tag. Must be called before outputting
     * any element content.
     */
    inline void startContent();

    /**
     * Escapes content intended as text nodes for elements.
     */
    void writeEscaped(const QString &toEscape);

    /**
     * Identical to writeEscaped(), but also escapes quotes.
     */
    inline void writeEscapedAttribute(const QString &toEscape);

    /**
     * Writes out @p name.
     */
    inline void write(const QXmlName &name);

    inline void write(const char *const chars);
    /**
     * Encodes and writes out @p content.
     */
    inline void write(const QString &content);

    Q_DECLARE_PRIVATE(QXmlSerializer)
};

QT_END_NAMESPACE

#endif
