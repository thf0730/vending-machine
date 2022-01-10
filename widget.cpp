#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);
}

int Widget::quotcalc(int price, int unit)
{
    quotient = price / unit;
    return quotient;
}

int Widget::remacalc(int price, int unit)
{
    remainder = price % unit;
    return remainder;
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}


int quot500, quot100, quot50, quot10;   //quotient : 몫
int rema500, rema100, rema50;   //remainder : 나머지
QString strmoney;   //money : 잔돈 문자열 변환
QString strquot500, strquot100, strquot50, strquot10;   //string+quotient : 몫 문자열 변환


void Widget::on_pbReset_clicked()
{

    quot500 = quotcalc(money, 500);   //500 배수 갯수
    rema500 = remacalc(money, 500);   //500 배수 제외 나머지

    quot100 = quotcalc(rema500, 100);   //100 배수 갯수
    rema100 = remacalc(money, 100);   //100 배수 제외 나머지

    quot50 = quotcalc(rema100, 50);   //50 배수 갯수
    rema50 = remacalc(money, 50);   //50 배수 제외 나머지

    quot10 = quotcalc(rema50, 10);   //10 배수 갯수

    strmoney = QString::number(money);
    strquot500 = QString::number(quot500);
    strquot100 = QString::number(quot100);
    strquot50 = QString::number(quot50);
    strquot10 = QString::number(quot10);

    QMessageBox::information(this, "반환", "남은 잔돈은 " + strmoney + "원입니다.\n\n" + "500원 " + strquot500 + "개, " + "100원 " + strquot100 + "개, " + "50원 " + strquot50 + "개, " + "10원 " + strquot10 + "개를 반환합니다.\n");

    changeMoney(-money);

}





