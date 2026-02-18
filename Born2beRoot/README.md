*This project has been created as part of the 42 curriculum by sgarba.*


# DESCRIPTION.

### BRIEF OVERVIEW OF BORN2BEROOT.

The main goal of Born2beRoot, is to introduce us to the world of virtualization, especially system administration, by creating our own Virtual Machine. This project is pretty broad, but very fun if you are interested in system administration.

### WHAT IS VIRTUALIZATION ?

Virtualization is a technology allowing us to create a virtual, simulated environment from a single physical machine; we could see it as a minicomputer inside a computer. Therefore, this simulated environment possesses its own Operating System, CPU, Memory, Network Interface, and Storage. Virtualization increases efficiency, retain flexibility and improve scalabilty. And to work it depends on two concepts:

_the first one is the VM (Virtual Machine). It is our computing environment with it's own ressources (CPU, Memory, etc.), and it can be defined by just one data file. This means it can be moved from computer to computer and be expected to work the same.
_the second concept is the Hypervisor or VMM (Virtual Machine Monitor). Hypervisors are software that separate a system's physical ressources and divides thos ressources so that the VM can use them as needed. VMM takes physical ressources from our computer and allocates them to multiple VM at once to enable the creation of new VM or the management of the existing ones.

### WHY I WENT FOR DEBIAN, HOW IT WAS SETUP, THE RULES I IMPLEMENTED AND COMPARISON OF SOME KEY CONCEPTS.

My first thought process was to go for Rocky, since it looks more secure and recommended according to my research, but Debian was definitely the best choice in my case, since I was completly new to VM Another main difference between Debian and Rocky that influenced me, is the fact that Rocky is more optimized for enterprise workloads, while Debian is more versatile from servers to desktops. Rocky is therefore more focused on stability and security making it very similar to RHEL (Red Hat Enterprise linux). Debian is highly customisazable for various need and might need rigorous testing to make it more stable.

First of all this is where I downloaded Debian https://www.debian.org/distrib/ . I went for <the 64-bit PC netinst iso> in the <small installation image>, because it install a minimal system, which is enough for Born2beRppt project.
During the setup of the VM, I went for 2048 MB (2GB) for better performance, 1 CPU to make it more a realistic, have fewer scheduling issues and use less of the host machine, and 30 GB on the Virtual Hard Disk avoid storage issue.

The partitioning was done using LVM (Logical Volume Management). LVM offers flexible disk management by creating virtual partitions or logical volumes from physical disk, allowing easier resizing and having multiple disks with their own sizes and purposes. I went an encrypted LVM, which means the data on the partitions were scrambled to protect sensitive informations from unauthorized access. Additionaly, I choose to go with the guided separate partitioning and separated in three important partitions:
/home which has the personal files, directories, configurations, etc, of each user,
/var (variable) stores data that change frequently (log files, tempory files, cache, database, etc) which is very helpful for trouble shot since almost everything is recorded,
/tmp is the temporary files storage for short term data we don't need to keep and is cleaned out on reboot. It keeps junk files serparatly.

We were asked to implement a strong password policy and install sudo following strict rules:
### Password policy.
Our password will expire every 30 days, requires minimum 2 days before being modified, the user is reminded 7 days before expiration to change the password, it must be at least 10c charaters long, contain minimum 1 uppercase letter, 1 lowercase letter and a number. It must not contain more than 3 consecutives identical characters and not include the name of the user. Al those rules also apply to root password except the rule that the new password must have at least 7 characters that are not part from the old one; this last rules only apply to user password.

### sudo (superuserdo)
It allow some users to execute somme commands as root. The strict rules applied to sudo are that the authentification using sudo must be limited to 3 attempts, we implement a custom message in case of wrong password, each action using sudo must be archived (both inputs and ouputs) and log file has to be saved in "/var/log/sudo" folder. We have to also enable TTY (TeleTYpe writer an old term for terminal session) mode, which make s sudo runs only from an actual terminal console where the user is logged in and not from script or backgroud processes without terminal. Very helpful to avoid automated attacks or scripts from running sudo command, ensure a human is actually present, add a layer of protection. The last security we had to add was to restrict sudo to this path: /usr/local/sbin:/usr/local/bin:/usr/bin:/sbin:/bin:/snap/bin

Additional security policies that I also implemented, are:

### UFW (Uncomplicated FireWall)
It is the default firewall configuration tool for Debian or Unbuntu. It was developed to ease iptables firewall configuration. Iptables is a powerful command-line utility for Linux that provides packet filtering, N.A.T. (Network address Translation) and other packet mangling which is chalanging for the uninitiated. Therefore we use UFW that provides a user friendly way to create an IPv4 (the standard IP addresses) and/ or an IPv6 (newer IP addresses). After the UFW setup, we make it only controls incoming and outgoing network traffic on port 4242, because the base port is set on 22, and when automated bot scan internet, they will focus on port 22.

### SSH (Secure SHell)
This service will be running on the mandatory port 4242. SSH is a cryptographic network protocol that allow users to securely access, control, and transfer files between computer over an unsecured network. Additionaly we make it so it is impossible to connect using SSH with root, because root has unlimited power and during attacks, attacker will always first try to connect with root.

And those are the main security policies and services installed on my VM. On top of that we can also do a comparison of some key concepts of Virtualization.

### AppArmor VS SELinux.
Both are MAC (Mandatory Access Control) that enhance Linux security. The key differences are that SELinux uses Type Enforcement and context labels for every file, process, and user making it quite complex to master. But it offers superior flexibilty for custom, and complex security policies. SELinux also support MLS (Multi-Level Security) and MCS (Multi-Context Security) that are both security scheme. AppArmor in comparison of SELinux uses profiles based on  file paths to define what ressources an application can access, making it generally easier to configure and manage. AppArmor is more static, ideal for defining specific, predictable behavior and lacks MLS/MCS support focusing primarily on application-level control. To conclude, SELinux for enterprise-grade security or complex systems and AppArmor for ease of use desktop environments or when needing effective application-specific confinment.

### UFW and firewalld.
They are both user-friendly front-ends for managing Linux netfilter. UFW is the default on Unbuntu/Debian while firewalld is default on Red Hat/CentOS/Fedora. UFW is designed for simplicity making it ideal for desktops and basic servers while firewalld is more advanced, supporting complex rules, services-based configurations, and network zones. In term of rules management, UFW applies rules statically, whereas firewalld manages rules dynamically, allowing for configurations changes without dropping existing connections. Another advantage of firewalld, is that it supports network zones to easily define trust levels for network interfaces, which UFW doesn't. UFW has a straighforward command-lines interface making it easier for beginners while firewalld uses firewall-cmd and XML-based configurations needing a steeper learning curve.

### VirtualBox VS UTM.
VirtualBox is open-source, meaning you can freely modify, use, contribute to its code. Meanwhile UTM is mac OS specific, that use Apples's Hypervisor framework resulting in better performances on Apple silicon Macs. VirtualBox though offer cross-platform support, working accross macOS, Windows and Linux, so you can manage Linux VMs on all your devices. VirtualBox also offers a wide range of distros (Linux distributions) and snapshots that allow you to save and restore the state of your VM and shared folders; additionally it also dispose of seamless mode which enbable Linux applications to run alongside masOS applications providingsmoother experience when switching between host and guest system. UTM though as fewer features, no seamless mode and advanced quest OS suport. It also support popular linux distros but fewer options than VirtualBox. Also UTM doesn't have graphical virtualization but VirtualBox has it. UTM provides a single masOS-friendly user interface, making it easier to set up as beginners compared to VirtualBox. UTM also uses fewer computer ressources compared to  VirtualBox.


# INSTRUCTIONS

Starting the VM is pretty straightforward; you press start in VirtualBox, enter the passphrase to unlock the encripted disk, user + password et voilà! So let's focus on important commands:
_first of all to have root acces you either login as root; username: root and root password. Or you can use the command <su --login> + the root password, or <sudo -s>/<sudo -i> + the user password.

_To install sudo, you first have to have root access. Afterwards, we need to run the command <apt install sudo> to install sudo on your OS. To check if sudo work properly you can run the command <sudo whoami> and it should show "root" since you are running this command as root user via sudo. To implement the sudo rules, run <sudo visudo> and NOT <sudo nano sudoers>! sudo nano edits directly, so no safety check while sudo visudo edit through visudo and check syntax errors before saving. To view the sudo command log we can run <sudo journalctl -g sudo>.

_To add a user to a group, run the command <sudo adduser {USER} {GROUP}>.

_To show all user run the command <getent passwd> or <getent group> to show all groups. You might also find useful to run <get group | grep {USER}> to show all groups with a specific username. The command <groups> show all groups the curent user is part of or you can run <groups {USER}> to show all groups another user is part of. To verify that a group exist we can run <grep '^{GROUP}' /etc/group>

_If you want to change your username, first of all login as root then run <usermode -l {NEW_USER} {OLD_USER}>. It might be possible that some process running in backgrounds stop the command to run, then you will have to run <pkill -u {USER}>. If it doesn't work you can use the stronger command <killall -u {USER}>. After changing username, you will also have to change the directory name with <usermod -d /home/{NEW_USER} -m {NEW_USER}>. Then rename the group (if it exists) with <groupmod -n {NEW_USER} {OLD_USER}>.

_To add a new user run the command <sudo adduser {USER}>, to add a new group we can run <sudo addgroup {GROUP}> and to delete a group or user we respectivly run <sudo delgroup {GROUP}> or <sudo deluser {USER}>.

_To install UFW wrun <sudo apt install ufw>, we then enable it with <sudo ufw enable>, and the default policies with those two commands: <sudo ufw default deny incoming> and <sudo ufw default allow outgoing> so our firewall allow outgoing connections and deny incoming ones. To allow a specific port we run <sudo ufw allow {PORT}>. If we want to check the status of UFW we run <sudo ufw status verbose> and to make sure that UFW start at boot we run <sudo systemctl enable ufw>.

_To output the numbered list of rules of UFW we run <sudo ufw status numbered> and to delete a specific line we can run <sudo ufw delete {LINE}>.

_To check the SSH status we run <sudo systemctl status ssh> or <sudo systemctl status ufw> for the firewall. And to restart the procces we can run <sudo systemctl restart ssh>.

_Other interesting commands are <systemctl --type=service> to list all loaded services even failed one, <systemctl --type=service --state=active> to list all active services, <journalctl> to print all log entries stored in the journal, <lsblk> to show the partition, <id {USER}> to show user's identity, <sudo apt update> to refresh system's package list from internet, <sudo apt install {PACKAGE}> to install the package, and <sudo apt upgrade> to upgrade installed packages.

_Let's also not forget the command <sudo apt install libpam-pwquality> to install the tool that enforces password complexity rules. We then run <sudo nano /etc/pam.d/common-password> to edit the file and enforce the stronbg policy rules.

_To change hostname, we will have to open two files; to modify them: <sudo nano /etc/hostname> and <sudo nano /etc/hosts>. To check the operating system we can either run <hostnamectl> or <cat /etc/os-release>.

_To manually apply the complex password rule to existing user before I updated pam_pwquality we can run <sudo chage -M 30 -m 2 -W 7 {USER}> and <sudo chage -M 30 -m 2 -W 7 {ROOT}>, since both were created before I added the complexity rules. The next users will automatically comply to those rules. -M is for maximum days, -m for minimum days and -W for warning.


# RESSOURCES.

Here are some of the links that helped me a lot during this project:

https://www.debian.org/distrib/

https://www.redhat.com/en/topics/virtualization/what-is-virtualization#how-does-virtualization-work

https://www.hostingseekers.com/blog/web-stories/rocky-linux-vs-debian-which-linux-distribution-to-pick/

https://amadla.medium.com/debian-linux-vs-rocky-os-exploring-the-best-choice-for-your-server-dfd6b3d80c1a

https://wiki.debian.org/sudo/

https://www.siberoloji.com/how-to-set-up-password-expiration-and-policies-in-debian-12-bookworm/

https://wiki.debian.org/Uncomplicated%20Firewall%20%28ufw%29

https://www.fastpanda.co.uk/knowledge-hub/how-to-change-the-ssh-port-on-ubuntu-debian#:~:text=sudo%20nano%20%2Fetc%2Fssh%2F,information%20with%20your%20desired%20port.

https://linuxize.com/post/bash-shebang/

https://m4nnb3ll.medium.com/my-experience-with-the-born2beroot-project-42-ad19d738ad4f

https://help.ubuntu.com/community/UFW

https://www.baeldung.com/linux/selinux-vs-apparmor

https://wiki.debian.org/SystemGroups

https://www.cyberciti.biz/faq/how-to-install-and-configure-sudo-on-debian-linux/

https://www.cyberciti.biz/faq/debian-change-hostname-permanently/

I also used AI to help me go deeper in the concept of virtualization if I didn't find any satisfactory answers on internet.