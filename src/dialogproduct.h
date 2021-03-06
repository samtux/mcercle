#ifndef DIALOGPRODUCT_H
#define DIALOGPRODUCT_H

#include <QDialog>
#include <QLocale>
#include "dbase.h"
#include "product.h"
#include "tax.h"

namespace Ui {
	class DialogProduct;
}

class DialogProduct : public QDialog {
	Q_OBJECT
public:
	DialogProduct(QLocale &lang, database *pdata, unsigned char type, QWidget *parent = 0);
	~DialogProduct();
	void setTitle(QString val);
	void loadValuesFormProduct();

protected:
	void changeEvent(QEvent *e);

private:
	Ui::DialogProduct *ui;
	database *m_data;
	product *m_product;
	tax *m_tax;
	QLocale m_lang;
	unsigned char m_type;
	QImage imgProduct;

	void loadProviderList();
	void loadCategoryList();
	void loadTaxList();
	void clearEdits();

private slots:
	void checkConditions();
	void on_toolButton_editCategorie_clicked();
	void on_pushButton_close_clicked();
	void on_pushButton_add_edit_clicked();
	void on_toolButton_editProvider_clicked();
	void on_toolButton_autoCode_clicked();
	void on_toolButton_editTax_clicked();

	void on_pushButton_image_clicked();
	
	void on_pushButton_ClearImage_clicked();
	
	signals:
	void askRefreshList();
};

enum{PRODUCT_ADD,PRODUCT_EDIT};
#endif // DIALOGPRODUCT_H
