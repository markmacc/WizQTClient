#ifndef WIZDOCUMENTLISTVIEW_H
#define WIZDOCUMENTLISTVIEW_H

#include <QListWidget>
#include "wizdef.h"


class CWizDocumentListViewItem;
class CWizCategoryView;
//
class CWizDocumentListView : public QListWidget
{
    Q_OBJECT
public:
    CWizDocumentListView(CWizExplorerApp& app, QWidget *parent = 0);
protected:
    CWizDatabase& m_db;
    CWizCategoryView& m_category;
public:
    void setDocuments(const CWizDocumentDataArray& arrayDocument);
    void addDocuments(const CWizDocumentDataArray& arrayDocument);
    //
    int addDocument(const WIZDOCUMENTDATA& data, bool sort);
    //
    bool acceptDocument(const WIZDOCUMENTDATA& document);
    //
    void addAndSelectDocument(const WIZDOCUMENTDATA& document);
public:
    void getSelectedDocuments(CWizDocumentDataArray& arrayDocument);

    virtual QSize sizeHint() const { return QSize(320, 1); }
public slots:
    void on_tag_created(const WIZTAGDATA& tag);
    void on_tag_modified(const WIZTAGDATA& tagOld, const WIZTAGDATA& tagNew);
    void on_document_created(const WIZDOCUMENTDATA& document);
    void on_document_modified(const WIZDOCUMENTDATA& documentOld, const WIZDOCUMENTDATA& documentNew);
    void on_document_deleted(const WIZDOCUMENTDATA& document);
    void on_document_AbstractModified(const WIZDOCUMENTDATA& document);
public:
    int documentIndexFromGUID(const CString& strGUID);
    CWizDocumentListViewItem *documentItemAt(int index);
    CWizDocumentListViewItem *documentItemFromIndex(const QModelIndex &index) const;
    WIZDOCUMENTDATA documentFromIndex(const QModelIndex &index) const;
    WIZABSTRACT documentAbstractFromIndex(const QModelIndex &index) const;
    CString documentTagsFromIndex(const QModelIndex &index) const;

};



#endif // WIZDOCUMENTLISTVIEW_H