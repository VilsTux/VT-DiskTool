### **VT-DiskTool (nur Linux)** 

# KOMPILIEREN

Das in C geschriebene Tool wird mit gcc kompiliert und braucht nur drei - in einem typischen Linux-System vorhandenen - Header-Dateien. Außerdem muss **gdisk** und **e2fsprogs** vorhanden sein (muss ggf. mit dem jeweiligen Paketmanager nachinstalliert werden). Eine Makefile ist vorhanden, welche nur mit "make" ausgefürt werden muss.

# BENUTZUNG

Das Tool ist ein Kommandozeilenprogramm. Bitte **mit sudo-Rechte ausführen**, sonst hat das Programm keinen Zugriff auf das Blockgerät.

Es wird hauptsächlich benutzt, um die Festplatten zu nullen, um sie wiederzuverwenden.
Das Programm unterstützt auch das Formatieren der Festplatten für die Nutzung unter Linux (ext4) oder Windows (NTFS).

**Changelog:**

- v0.1 (29.10.2023): Erste stabile Version des Tools
- v0.2 (?): DiskTool zeigt nun vor der Eingabe des Gerätes alle Blockgeräte mit lsblk an

(C) 2023 VilsTux - MIT-Lizenz
