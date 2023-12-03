#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

void banner(string indice) {
    system("clear");
    system("figlet Packet Tracer");
    system("figlet - Assistant -");
    cout << "                                              Hecho por: Álvaro Salas Robledillo";
    cout << endl;
    cout << indice << endl << endl;
}

void configSSH() {
    //! Declaración de varibles
    string indice = "Configuración SSH.";
    string hostname, domainName, cifrate, userName, secret, optDef;
    bool sshVer2 = false; 
    int optSsh;

    //! Entrada de datos
    hostname = "ssh-device";
    domainName = "cisco.com";
    cifrate = "1024";
    userName = "cisco";
    secret = "Cisco1234";

    banner(indice);

    cout << endl << "¿Desea utilizar una configuración estándar? (s/n)\n> "; cin >> optDef;
    cout << endl;

    if (optDef != "s") {
        banner(indice);
        cout << "Versión SSH (1/2).\n> "; cin >> optSsh;

        if (optSsh == 2) {
            sshVer2 = true;
        }

        cout << "Hostname.\n> "; cin >> hostname;
        cout << "Domain-Name.\n> "; cin >> domainName;
        cout << "Cifrado (360-2048).\n> "; cin >> cifrate;
        cout << "Nombre de usuario.\n> "; cin >> userName;
        cout << "Contraseña.\n> "; cin >> secret;
    }
    
    else {
        sshVer2 = true;
    }

    //! Salida de datos
    
    banner(indice);
    cout << "- - - Configuración SSH - - -" << endl << endl;
    cout << "hostname " << hostname << endl;
    cout << "ip domain-name " << domainName << endl;
    cout << "crypto key generate rsa general-keys modulus " << cifrate << endl;
    cout << "username " << userName << " secret " << secret << endl;
    cout << "line vty 0 15" << endl;
    cout << "login local" << endl;
    cout << "transport input ssh" << endl;
    cout << "exit" << endl;

    if (sshVer2 == true)
        cout << "ip ssh version 2" << endl;
        cout << endl;

    string next;

    cout << "Continuar... (s/n)\n> "; cin >> next;
    cout << endl;

}

void configDHCP() {
    //! Declaración de varibles
    string indice = "Configuración DHCP.";
    int poolQty;
    string pools[20], networkID[20], dns, domainNameDHCP;

    //! Entrada de datos
    banner(indice);
    cout << "¿Cúantas pools necesita?\n> "; cin >> poolQty;
    cout << endl;

    for (int i = 0; i < poolQty; i++) {
        cout << "ID Pool " << i + 1 << ".\n> "; cin >> pools[i];
        cout << "ID de red (ej: 192.168.0).\n> "; cin >> networkID[i];
        cout << endl;
    }

    cout << "Servidor DNS (no = 0).\n> "; cin >> dns;
    cout << endl;
    cout << "Domain name (no = 0).\n> "; cin >> domainNameDHCP;

    //! Salida de datos
    banner(indice);

    cout << "- - - Configuración DHCPv4 - - -" << endl << endl;
    for (int i = 0; i < poolQty; i++) {
        cout << "ip dhcp excluded-address " << networkID[i] << ".1" << endl;
        cout << "ip dhcp pool " << pools[i] << endl;
        cout << "network " << networkID[i] << ".0 255.255.255.0" << endl;
        cout << "default-router " << networkID[i] << ".1" << endl;
        if (dns != "0") {
            cout << "dns-server " << dns << endl;
        }
        if (domainNameDHCP != "0") {
            cout << "domain-name " << domainNameDHCP << endl; 
        }
        cout << "exit" << endl;
    }

    cout << endl;

    string next;

    cout << "Continuar... (s/n)\n> "; cin >> next;
    cout << endl;

}

void configHSRP() {
    //! Declaración de varibles
    string indice = "Configuración HSRP.";
    int groupQty;
    string HSRP[10][3]; //! INTERFACES | GRUPOS | IDRED

    //! Entrada de datos
    banner(indice);
    cout << "¿Cúantos grupos necesita?\n> "; cin >> groupQty;

    for (int i = 0; i < groupQty; i++) {
        cout << "\nGrupo " << i + 1 << "." << endl;
        cout << "ID grupo.\n> "; cin >> HSRP[i][1];
        cout << "ID red (ej: 192.168.0).\n> "; cin >> HSRP[i][2];
    }
    
    //! Salida de datos
    banner(indice);

    for (int i = 0; i < groupQty; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                cout << "- - - Configuración HSRP rúter principal - - -" << endl << endl;
                cout << "ip address " << HSRP[i][2] << ".250 255.255.255.0" << endl;
                cout << "standby " << HSRP[i][1] << " ip " << HSRP[i][2] << ".1" << endl;
                cout << "standby " << HSRP[i][1] << " priority 200" << endl;
                cout << "standby " << HSRP[i][1] << " preempt" << endl;
                cout << "no shutdown" << endl;
                cout << "exit" << endl;
                cout << endl;
            }
            else {
                cout << "- - - Configuración HSRP rúter secundario - - -" << endl << endl;
                cout << "ip address " << HSRP[i][2] << ".240 255.255.255.0" << endl;
                cout << "standby " << HSRP[i][1] << " ip " << HSRP[i][2] << ".1" << endl;
                cout << "standby " << HSRP[i][1] << " priority 100" << endl;
                cout << "no shutdown" << endl;
                cout << "exit" << endl;
                cout << endl;
            }
        }
    }

    string next;

    cout << "Continuar... (s/n)\n> "; cin >> next;
    cout << endl;

}

void configOSPF(int acNetworks) {
    //! Declaración de varibles
    string indice = "Configuración OSPF.";
    string ospfNetworks[20][2];

    //! Entrada de datos
    banner(indice);
    for (int i = 0; i < acNetworks; i++) {
        cout << "Red " << i + 1 << " (ej: 10.0.0.0 0.0.0.3).\n> ";
        cin >> ospfNetworks[i][0];
        cin >> ospfNetworks[i][1];
        cout << endl;
    }

    //! Salida de datos
    banner(indice);
    cout << "- - - Configuración OSPF - - -" << endl << endl;
    cout << "router ospf 10" << endl;
    for (int i = 0; i < acNetworks; i++) {
        cout << "network " << ospfNetworks[i][0] << " " << ospfNetworks[i][1] << " area 0" << endl;
    }
    cout << "exit" << endl;
    cout << endl;

    string next;

    cout << "Continuar... (s/n)\n> "; cin >> next;
    cout << endl;

}

void configRIP(int acNetworks) {
    //! Declaración de varibles
    string indice = "Configuración RIP.";
    string ripNetworks[20];

    //! Entrada de datos
    banner(indice);
    for (int i = 0; i < acNetworks; i++) {
        cout << "Red " << i + 1 << " (ej: 10.0.0.0).\n> ";
        cin >> ripNetworks[i];
        cout << endl;
    }

    //! Salida de datos
    banner(indice);
    cout << "- - - Configuración RIP - - -" << endl << endl;
    cout << "router rip" << endl;
    cout << "version 2" << endl;
    for (int i = 0; i < acNetworks; i++) {
        cout << "network " << ripNetworks[i] << endl;
    }
    cout << "exit" << endl;
    cout << endl;

    string next;

    cout << "Continuar... (s/n)\n> "; cin >> next;
    cout << endl;

}

void configTRUNK() {
    //! Declaración de varibles
    string indice = "Configuración troncales.";
    int vlanQty;
    string nativeVlan, vlan[20], opcSwitch;
    bool l3switch = false;

    //! Entrada de datos
    banner(indice);
    cout << "¿Switch multicapa? (s/n)\n> "; cin >> opcSwitch;
    cout << endl;

    if (opcSwitch == "s" || opcSwitch == "S") {
        l3switch = true;
    }

    cout << "¿Cúantas VLAN necesita?\n> "; cin >> vlanQty;
    cout << endl;
    cout << "¿Cúal es la VLAN nativa?\n> "; cin >> nativeVlan;
    
    cout << endl;
    for (int i = 0; i < vlanQty; i++) {
        cout << "ID Vlan " << i + 1 << "\n> ";
        cin >> vlan[i];
        cout << endl;
    }
    
    //! Salida de datos
    banner(indice);
    cout << "- - - Creación VLAN - - -" << endl << endl;
    for (int i = 0; i < vlanQty; i++) {
        cout << "vlan " << vlan[i] << endl;
        cout << "exit" << endl;
    }

    if (nativeVlan != "1") {
        cout << "Vlan " << nativeVlan << endl;
        cout << "exit" << endl;
    } 

    cout << endl;
    cout << "- - - Configuración troncales - - -" << endl << endl;
    if (l3switch) {
        cout << "switchport trunk encapsulation dot1q" << endl;
    }
    cout << "switchport mode trunk" << endl;
    cout << "switchport trunk allowed vlan ";
    for (int i = 0; i < vlanQty; i++) {
        cout << vlan[i] << ",";
    }
    
    if (nativeVlan != "1") {
        cout << nativeVlan << endl;
        cout << "switchport trunk native vlan " << nativeVlan;
    }
    else {
        cout << "1";
    }

    cout << endl << endl;

    string next;

    cout << "Continuar... (s/n)\n> "; cin >> next;
    cout << endl;

}

void configSubInt() {
    int interfaceQty;
    string indice = "Configuración subinterfaces rúter.";
    string interfaz, native;

    banner(indice);
    cout << "¿Interfaz?\n> "; cin >> interfaz;
    cout << endl;
    cout << "¿Cúantas subinterfaces quiere?\n> "; cin >> interfaceQty;
    cout << endl;
    cout << "ID Vlan nativa (no = 0)\n> "; cin >> native;
    cout << endl;

    string vlanInt[interfaceQty];

    //! Entrada de datos

    for (int i = 0; i < interfaceQty; i++) {
        cout << "ID Vlan subinterfaz " << i + 1 << "\n> ";
        cin >> vlanInt[i];
    }

    //! Salida de datos

    banner(indice);
    cout << "- - - Configuración Subinterfaces - - -" << endl << endl;
    cout << "interface " << interfaz << endl;
    cout << "no shutdown" << endl;
    cout << "exit" << endl;
    for (int i = 0; i < interfaceQty; i++) {
        cout << "interface " << interfaz << "." << vlanInt[i] << endl;
        if (vlanInt[i] == native) {
            cout << "encapsulation dot1q " << vlanInt[i] << " native" << endl;
        }
        else {
            cout << "encapsulation dot1q " << vlanInt[i] << endl;
        }
        cout << "ip address 192.168." << vlanInt[i] << ".1 255.255.255.0" << endl;
        cout << "no shutdown" << endl;
        cout << "exit" << endl;
    }
    cout << endl;

    string next;

    cout << "Continuar... (s/n)\n> "; cin >> next;
    cout << endl;
}

void configRouting() {
    int selProtocol, acNetworks;
    string indice = "Configuración enrutamiento.";

    banner(indice);

    cout << "¿Cuantas redes están directamente conectadas?\n> "; cin >> acNetworks;
    cout << endl << "¿Qué protocolo de enrutamiento va a usar?" << endl << endl;
    cout << "1. OSPF." << endl;
    cout << "2. RIP." << endl;
    cout << endl << "> "; cin >> selProtocol;

    banner(indice);

    switch (selProtocol) {
        case 1: //- OSPF
            configOSPF(acNetworks);
        break;

        case 2: //- RIP
            configRIP(acNetworks);
        break;

        default:
        break;
    }
}

void soloMode () {
    //! Declaración de variables.
    string indice = "Modo solitario.";
    int opcion;
    string temp;

    banner(indice);

    cout << "Seleccione una opción." << endl << endl;
    cout << "1. SSH." << endl;
    cout << "2. DHCPv4." << endl;
    cout << "3. HSRP." << endl;
    cout << "4. Enrutamiento." << endl;
    cout << "5. Configuración troncales." << endl;
    cout << "6. Subinterfaces rúter." << endl;
    cout << endl << "7. Salir." << endl;
    cout << endl << "> ";

    cin >> opcion;

    banner(indice);

    switch (opcion) {

        case 1: //- SSH
            configSSH();
        break;

        case 2: //- DHCPv4 ROUTER (/24)
            configDHCP();
        break;

        case 3: //- HSRP
            configHSRP();
        break;
        
        case 4: //- Enrutamiento
            configRouting();
        break;

        case 5: //- Troncales
            configTRUNK();
        break;

        case 6:
            configSubInt();
        break;

        case 7:
        system("clear");
        break;

        default:
        break;
    }
    
    cout << "¿Desea probar otra configuración? (s/n)\n> "; cin >> temp;

    if (temp == "s" || temp == "S")
        soloMode();
    else
        system("clear");
}

void statusCheck(bool switchExists, bool routerExists, bool sshExists, bool switchFin, bool routerFin, bool sshFin) {

    string next;
    string indice = "Estado de la configuración.";

    banner(indice);

    cout << "[";
    if (switchFin)
        cout << "*";
    else if (!switchExists)
        cout << "-";
    else {
        cout << " ";
    }
    cout << "] Configuración switch." << endl;
    cout << "[";
    if (routerFin)
        cout << "*";
    else if (!routerExists)
        cout << "-";
    else {
        cout << " ";
    }
    cout << "] Configuración rúter." << endl;
    cout << "[";
    if (sshFin)
        cout << "*";
    else if (!sshExists)
        cout << "-";
    else {
        cout << " ";
    }
    cout << "] Configuración SSH." << endl;
    cout << endl;

    cout << "Continuar... (s/n)\n> "; cin >> next;
    cout << endl;

}

void assistedMode() {
    //! Declaración de variables.
    string indice = "Modo asistido.";

    string opcion;

    bool switchExists = false;
    bool routerExists = false;
    bool sshExists = false;

    bool switchFin = false;
    bool routerFin = false;
    bool sshFin = false;

    bool trunkAnswer = false;
    bool dot1qAnswer = false;
    bool routingAnswer = false;
    bool dhcpAnswer = false;
    bool hsrpAnswer = false;

    banner(indice);

    cout << "¿Desea configurar switchs? (s/n)\n> "; cin >> opcion;
    if (opcion == "s" || opcion == "S"){
        switchExists = true;
        cout << "¿Va a requerir del uso de vlans y cables troncales? (s/n)\n> "; cin >> opcion;
        cout << endl;
        if (opcion == "s" || opcion == "S"){
            trunkAnswer = true;
        }
    }
    cout << "¿Desea configurar rúters? (s/n)\n> "; cin >> opcion;
    if (opcion == "s" || opcion == "S"){
        routerExists = true;
        cout << "¿Necesita el protocolo dot1Q? (s/n)\n> "; cin >> opcion;
        if (opcion == "s" || opcion == "S"){
            dot1qAnswer = true;
        }
        cout << "¿Necesita enrutar? (s/n)\n> "; cin >> opcion;
        if (opcion == "s" || opcion == "S"){
            routingAnswer = true;
        }
        cout << "¿Necesita DHCP en router? (s/n)\n> "; cin >> opcion;
        if (opcion == "s" || opcion == "S"){
            dhcpAnswer = true;
        }
        cout << "¿Va a utilizar HSRPv4? (s/n)\n> "; cin >> opcion;
        cout << endl;
        if (opcion == "s" || opcion == "S"){
            hsrpAnswer = true;
        }
    }
    cout << "¿Necesita SSH? (s/n)\n> "; cin >> opcion;
    if (opcion == "s" || opcion == "S"){
        sshExists = true;
    }

    statusCheck(switchExists, routerExists, sshExists, switchFin, routerFin, sshFin);

    //! Config Switch
    if (switchExists) {
        if (!switchFin) {
            if (trunkAnswer == true) {
                configTRUNK();
            }
            switchFin = true;
            statusCheck(switchExists, routerExists, sshExists, switchFin, routerFin, sshFin);
        }
    }

    if (routerExists) {
        if (!routerFin) {
            if (dot1qAnswer == true) {
                configSubInt();
            }
            banner(indice);
            if (dhcpAnswer == true) {
                configDHCP();
            }
            if (hsrpAnswer == true) {
                configHSRP();
            }
            if (routingAnswer == true) {
                configRouting();
            }
            routerFin = true;
            statusCheck(switchExists, routerExists, sshExists, switchFin, routerFin, sshFin);
        }
    }

    if (sshExists) {
        if (!sshFin) {
            configSSH();
            sshFin = true;
            statusCheck(switchExists, routerExists, sshExists, switchFin, routerFin, sshFin);
        }
    }

}

int main() {

    string indice = "";
    string tempOpc;
    int opcion;

    banner(indice);

    cout << "Seleccione una opción." << endl << endl;
    cout << "1. Modo asistido." << endl;
    cout << "2. Modo solitario." << endl;
    cout << endl << "3. Salir." << endl;
    cout << endl << "> ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            assistedMode();
            break;

        case 2:
            soloMode();
            break;

        default:
        break;
    }

    banner("Cerrar el programa.");
    cout << "¿Salir? (s/n)\n> "; cin >> tempOpc;

    if (tempOpc == "n" || tempOpc == "N")
        main();
    else
        system("clear");
        return 0;

}
