#include <QtWidgets>
#include <QtNetwork>

#include "client.h"
#include "loginwindow.h"

Client::Client(LoginWindow *parent)
    //: QDialog(parent)
    //, hostCombo(new QComboBox)
    //, portLineEdit(new QLineEdit)
    //, getFortuneButton(new QPushButton(tr("Get Fortune")))
    //, tcpSocket(new QTcpSocket(this))
{
    this->parent = parent;
    hostCombo = new QComboBox(parent);
    hostCombo->setGeometry(QRect(QPoint(200,50),QSize(200,20)));
    hostCombo->setEditable(true);
    // find out name of this machine
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty()) {
        hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            hostCombo->addItem(name + QChar('.') + domain);
    }
    if (name != QLatin1String("localhost"))
        hostCombo->addItem(QString("localhost"));
    // find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (!ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }
    // add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    portLineEdit = new QLineEdit(parent);
    portLineEdit->setGeometry(QRect(QPoint(200,80),QSize(200,20)));
    portLineEdit->setValidator(new QIntValidator(1, 65535, parent));
    auto hostLabel = new QLabel("&Server name:");
    hostLabel->setBuddy(hostCombo);
    auto portLabel = new QLabel("&Server port:");
    portLabel->setBuddy(portLineEdit);
    portLineEdit->setFocus();

    // NETWORK CONFIGURE

    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

   // QObject::connect(parent->getLoginButton(),parent->getLoginButton()->clicked() ,parent, Client::enableGetFortuneButton());
    //connect(portLineEdit, &QLineEdit::textChanged, parent, &Client::enableGetFortuneButton);
   // connect(parent->getLoginButton(), SIGNAL(clicked()), this, SLOT(readFortune()));
   // connect(tcpSocket, &QIODevice::readyRead, this, &Client::readFortune);
    //connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this, &Client::displayError);



    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, parent);
        //connect(networkSession, &QNetworkSession::opened, this, &Client::sessionOpened);

        parent->getLoginButton()->setEnabled(false);
        statusLabel->setText("Opening network session.");
        networkSession->open();
    }
}

void Client::requestNewFortune()
{
    /*
    getFortuneButton->setEnabled(false);
    tcpSocket->abort();
    tcpSocket->connectToHost(hostCombo->currentText(),
                             portLineEdit->text().toInt());
*/}

void Client::readFortune()
{/*
    in.startTransaction();

    QString nextFortune;
    in >> nextFortune;

    if (!in.commitTransaction())
        return;

    if (nextFortune == currentFortune) {
        QTimer::singleShot(0, this, &Client::requestNewFortune);
        return;
    }

    currentFortune = nextFortune;
    statusLabel->setText(currentFortune);
    getFortuneButton->setEnabled(true);
*/}

void Client::displayError(QAbstractSocket::SocketError socketError)
{/*
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));
    }

    getFortuneButton->setEnabled(true);
*/}

void Client::enableGetFortuneButton()
{
    /*
    getFortuneButton->setEnabled((!networkSession || networkSession->isOpen()) &&
                                 !hostCombo->currentText().isEmpty() &&
                                 !portLineEdit->text().isEmpty());

*/}

void Client::sessionOpened()
{/*
    // Save the used configuration
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        id = config.identifier();

    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();

    statusLabel->setText(tr("This examples requires that you run the "
                            "Fortune Server example as well."));

    enableGetFortuneButton();
*/}
