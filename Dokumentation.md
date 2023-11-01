### **VT-DiskTool (nur Linux)** 

# KOMPILIEREN

Das in C geschriebene Tool wird mit gcc kompiliert und braucht nur drei - in einem typischen Linux-System vorhandenen - Header-Dateien. Eine Makefile ist vorhanden, welche nur mit "make" ausgefürt werden muss. Somit ist das Programm kompiliert.

# BENUTZUNG

Das Tool ist ein Kommandozeilenprogramm. Bitte **mit sudo-Rechte ausführen**, sonst hat das Programm keinen Zugriff auf das Blockgerät.

Es wird hauptsächlich benutzt, um die Festplatten unserer Mitarbeiter zu nullen, um sie wiederzuverwenden.
Das Programm unterstützt auch das Formatieren der Festplatten für die Nutzung unter Linux (ext4) oder Windows (NTFS).

**Changelog:**

- v0.1 (29.10.2023): Erste stabile Version des Tools
- v0.2 (?): DiskTool zeigt nun vor der Eingabe des Gerätes alle Blockgeräte mit lsblk an

(C) 2023 VilsTux - MIT-Lizenz