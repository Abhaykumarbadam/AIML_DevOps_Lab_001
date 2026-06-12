# DevOps Lab — All 27 Programs
### Complete Step-by-Step Guide with Debugging & Viva Questions

---

# Before Starting — Linux Setup

## Install Git

```bash
sudo apt update
sudo apt install git -y
```

Verify:

```bash
git --version
```

Expected: `git version 2.x.x`

---

## Install Docker

```bash
sudo apt update
sudo apt install docker.io -y
sudo systemctl enable docker
sudo systemctl start docker
```

Verify:

```bash
docker --version
```

Add current user to Docker group:

```bash
sudo usermod -aG docker $USER
```

Logout and login again, then test:

```bash
docker run hello-world
```

---

## Install kubectl

```bash
curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl"
chmod +x kubectl
sudo mv kubectl /usr/local/bin/
```

Verify:

```bash
kubectl version --client
```

---

## Install Minikube

```bash
curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
sudo install minikube-linux-amd64 /usr/local/bin/minikube
minikube start --driver=docker
kubectl get nodes
```

---

## Common Viva Commands

### Five Git Commands

| Command | Usage |
|---|---|
| `git init` | Create repository |
| `git clone` | Copy repository |
| `git add` | Stage files |
| `git commit` | Save changes |
| `git push` | Upload to GitHub |

### Five Docker Commands

| Command | Usage |
|---|---|
| `docker pull` | Download image |
| `docker build` | Build image |
| `docker run` | Run container |
| `docker ps` | List containers |
| `docker images` | List images |

### Five Kubernetes Commands

| Command | Usage |
|---|---|
| `kubectl get pods` | Show pods |
| `kubectl get nodes` | Show nodes |
| `kubectl create deployment` | Create deployment |
| `kubectl describe pod` | Details of pod |
| `kubectl delete pod` | Delete pod |

---

### Practical Exam Flow (Fastest Method)

1. Show 5 Git commands
2. Show 5 Docker commands
3. Show 5 Kubernetes commands
4. Create program
5. Run locally
6. Create Dockerfile
7. Build image
8. Run container
9. Push code to GitHub
10. Push image to DockerHub
11. Show GitHub repo
12. Show DockerHub image

---

---

# PROGRAM 1 — Java + Docker + GitHub + DockerHub

---

## Step 1: Create Folder

```bash
mkdir java-devops
cd java-devops
```

## Step 2: Create Java Program

```bash
nano HelloWorld.java
```

```java
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello DevOps Lab");
    }
}
```

Save: `CTRL+O` → `ENTER` → `CTRL+X`

## Step 3: Test Java Program

```bash
sudo apt install default-jdk -y
javac HelloWorld.java
java HelloWorld
```

Expected output: `Hello DevOps Lab`

**Debug:**

| Error | Fix |
|---|---|
| `javac: command not found` | `sudo apt install default-jdk -y` |
| `ClassNotFoundException` | Run `javac HelloWorld.java` then `java HelloWorld` (no `.java` extension) |

## Step 4: Create Dockerfile

```bash
nano Dockerfile
```

```dockerfile
FROM openjdk:17
WORKDIR /app
COPY HelloWorld.java .
RUN javac HelloWorld.java
CMD ["java","HelloWorld"]
```

## Step 5: Build Docker Image

```bash
docker build -t java-devops .
docker images
```

**Debug:**

| Error | Fix |
|---|---|
| `Cannot connect to Docker daemon` | `sudo systemctl start docker` |
| `permission denied` | `sudo usermod -aG docker $USER` then Logout/Login |

## Step 6: Run Container

```bash
docker run java-devops
```

Expected output: `Hello DevOps Lab`

## Step 7: Push Code to GitHub

```bash
git init
git add .
git commit -m "Initial Commit"
git remote add origin https://github.com/USERNAME/java-devops.git
git branch -M main
git push -u origin main
```

**Debug — Author identity unknown:**

```bash
git config --global user.name "YourName"
git config --global user.email "you@gmail.com"
```

## Step 8: Push Image to DockerHub

```bash
docker login
docker tag java-devops USERNAME/java-devops:v1
docker push USERNAME/java-devops:v1
```

---

---

# PROGRAM 2 — C Program + Docker + GitHub + DockerHub

---

## Step 1: Create Folder

```bash
mkdir c-devops
cd c-devops
```

## Step 2: Create Program

```bash
nano hello.c
```

```c
#include<stdio.h>

int main() {
    printf("Hello DevOps Lab\n");
    return 0;
}
```

## Step 3: Test Program

```bash
sudo apt install gcc -y
gcc hello.c -o hello
./hello
```

Expected output: `Hello DevOps Lab`

**Debug — `gcc command not found`:** `sudo apt install gcc -y`

## Step 4: Create Dockerfile

```bash
nano Dockerfile
```

```dockerfile
FROM gcc:latest
WORKDIR /app
COPY hello.c .
RUN gcc hello.c -o hello
CMD ["./hello"]
```

## Step 5: Build and Run

```bash
docker build -t c-devops .
docker run c-devops
```

Expected output: `Hello DevOps Lab`

## Step 6: Push to GitHub

```bash
git init
git add .
git commit -m "C Program"
git remote add origin https://github.com/USERNAME/c-devops.git
git push -u origin main
```

## Step 7: Push to DockerHub

```bash
docker login
docker tag c-devops USERNAME/c-devops:v1
docker push USERNAME/c-devops:v1
```

---

---

# PROGRAM 3 — HTML + Docker + GitHub + DockerHub

---

## Step 1: Create Folder

```bash
mkdir html-devops
cd html-devops
```

## Step 2: Create HTML File

```bash
nano index.html
```

```html
<!DOCTYPE html>
<html>
<head>
  <title>DevOps Lab</title>
</head>
<body>
  <h1>Hello DevOps Lab</h1>
</body>
</html>
```

## Step 3: Test Locally

```bash
xdg-open index.html
```

## Step 4: Create Dockerfile

```bash
nano Dockerfile
```

```dockerfile
FROM nginx:latest
COPY index.html /usr/share/nginx/html/index.html
```

## Step 5: Build Image

```bash
docker build -t html-devops .
```

## Step 6: Run Container

```bash
docker run -d -p 8080:80 html-devops
docker ps
```

Open: `http://localhost:8080`

Expected output: `Hello DevOps Lab`

**Debug:**

| Error | Fix |
|---|---|
| `bind: address already in use` | Use `-p 8081:80` and open `http://localhost:8081` |
| Container not running | `docker logs CONTAINER_ID` |

## Step 7: Push Code to GitHub

```bash
git init
git add .
git commit -m "HTML Project"
git remote add origin https://github.com/USERNAME/html-devops.git
git push -u origin main
```

## Step 8: Push Image to DockerHub

```bash
docker login
docker tag html-devops USERNAME/html-devops:v1
docker push USERNAME/html-devops:v1
```

---

---

# PROGRAM 4 — Python Program + Docker + GitHub + DockerHub

---

## Step 1: Create Project

```bash
mkdir python-devops
cd python-devops
```

## Step 2: Create Python Program

```bash
nano app.py
```

```python
print("Hello DevOps Lab")
```

## Step 3: Test Program

```bash
python3 --version
python3 app.py
```

Expected output: `Hello DevOps Lab`

**Debug — `python3: command not found`:** `sudo apt install python3 -y`

## Step 4: Create Dockerfile

```bash
nano Dockerfile
```

```dockerfile
FROM python:3.11
WORKDIR /app
COPY app.py .
CMD ["python","app.py"]
```

## Step 5: Build Image

```bash
docker build -t python-devops .
docker images
```

## Step 6: Run Container

```bash
docker run python-devops
```

Expected output: `Hello DevOps Lab`

## Step 7: Push to GitHub

```bash
git init
git add .
git commit -m "Python Program"
git branch -M main
git remote add origin https://github.com/USERNAME/python-devops.git
git push -u origin main
```

## Step 8: Push to DockerHub

```bash
docker login
docker tag python-devops USERNAME/python-devops:v1
docker push USERNAME/python-devops:v1
```

---

---

# PROGRAM 5 — Node.js Program + Docker + GitHub + DockerHub

---

## Step 1: Create Project

```bash
mkdir node-devops
cd node-devops
```

## Step 2: Create Program

```bash
nano app.js
```

```javascript
console.log("Hello DevOps Lab");
```

## Step 3: Install Node.js and Test

```bash
sudo apt update
sudo apt install nodejs npm -y
node -v
npm -v
node app.js
```

Expected output: `Hello DevOps Lab`

**Debug — `node: command not found`:** `sudo apt install nodejs npm -y`

## Step 4: Create Dockerfile

```bash
nano Dockerfile
```

```dockerfile
FROM node:20
WORKDIR /app
COPY app.js .
CMD ["node","app.js"]
```

## Step 5: Build Image

```bash
docker build -t node-devops .
```

## Step 6: Run Container

```bash
docker run node-devops
```

Expected output: `Hello DevOps Lab`

## Step 7: Push to GitHub

```bash
git init
git add .
git commit -m "Node Program"
git branch -M main
git remote add origin https://github.com/USERNAME/node-devops.git
git push -u origin main
```

## Step 8: Push to DockerHub

```bash
docker login
docker tag node-devops USERNAME/node-devops:v1
docker push USERNAME/node-devops:v1
```

---

---

# PROGRAM 6 — Flask Application + Docker + GitHub + DockerHub

---

## Step 1: Create Project

```bash
mkdir flask-devops
cd flask-devops
```

## Step 2: Create Flask App

```bash
nano app.py
```

```python
from flask import Flask

app = Flask(__name__)

@app.route('/')
def home():
    return "Hello DevOps Lab"

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
```

## Step 3: Create requirements.txt

```bash
nano requirements.txt
```

```
flask
```

## Step 4: Install Flask and Run

```bash
pip3 install flask
python3 app.py
```

Open: `http://localhost:5000`

**Debug — `ModuleNotFoundError: No module named flask`:** `pip3 install flask`

## Step 5: Create Dockerfile

```bash
nano Dockerfile
```

```dockerfile
FROM python:3.11
WORKDIR /app
COPY . .
RUN pip install -r requirements.txt
EXPOSE 5000
CMD ["python","app.py"]
```

## Step 6: Build Image

```bash
docker build -t flask-devops .
```

## Step 7: Run Container

```bash
docker run -d -p 5000:5000 flask-devops
docker ps
```

Open: `http://localhost:5000`

## Step 8: Push to GitHub

```bash
git init
git add .
git commit -m "Flask Project"
git branch -M main
git remote add origin https://github.com/USERNAME/flask-devops.git
git push -u origin main
```

## Step 9: Push to DockerHub

```bash
docker login
docker tag flask-devops USERNAME/flask-devops:v1
docker push USERNAME/flask-devops:v1
```

---

---

# PROGRAM 7 — C Program + GitHub + Jenkins Job

---

## Step 1: Install Jenkins

```bash
sudo apt update
sudo apt install openjdk-17-jdk -y

curl -fsSL https://pkg.jenkins.io/debian-stable/jenkins.io-2023.key | sudo tee \
/usr/share/keyrings/jenkins-keyring.asc > /dev/null

echo deb [signed-by=/usr/share/keyrings/jenkins-keyring.asc] \
https://pkg.jenkins.io/debian-stable binary/ | sudo tee \
/etc/apt/sources.list.d/jenkins.list > /dev/null

sudo apt update
sudo apt install jenkins -y
sudo systemctl enable jenkins
sudo systemctl start jenkins
sudo systemctl status jenkins
```

## Step 2: Access Jenkins

Open: `http://localhost:8080`

Get initial password:

```bash
sudo cat /var/lib/jenkins/secrets/initialAdminPassword
```

## Step 3: Create C Program

```bash
nano hello.c
```

```c
#include<stdio.h>

int main() {
    printf("Hello Jenkins\n");
    return 0;
}
```

## Step 4: Push to GitHub

```bash
git init
git add .
git commit -m "C Jenkins"
git remote add origin https://github.com/USERNAME/c-jenkins.git
git push -u origin main
```

## Step 5: Create Jenkins Freestyle Job

- Dashboard → New Item
- Name: `C-Program`
- Select: `Freestyle Project`

## Step 6: Configure Git

- Source Code Management → Git
- Repository URL: `https://github.com/USERNAME/c-jenkins.git`

## Step 7: Add Build Step

- Add Build Step → Execute Shell

```bash
gcc hello.c -o hello
./hello
```

## Step 8: Build Now

Console Output: `Hello Jenkins`

**Debug — `gcc: command not found`:** `sudo apt install gcc -y`

---

---

# PROGRAM 8 — Python Calculator + GitHub + Jenkins Job

---

## Step 1: Create Project

```bash
mkdir calculator
cd calculator
```

## Step 2: Create Calculator

```bash
nano calculator.py
```

```python
a = 20
b = 10

print("Addition =", a+b)
print("Subtraction =", a-b)
print("Multiplication =", a*b)
print("Division =", a/b)
```

## Step 3: Test Program

```bash
python3 calculator.py
```

Expected output:

```
Addition = 30
Subtraction = 10
Multiplication = 200
Division = 2.0
```

## Step 4: Push to GitHub

```bash
git init
git add .
git commit -m "Python Calculator"
git branch -M main
git remote add origin https://github.com/USERNAME/python-calculator.git
git push -u origin main
```

## Step 5: Create Jenkins Job

- New Item → Name: `Python-Calculator` → Freestyle Project

## Step 6: Configure Git

- Repository URL: `https://github.com/USERNAME/python-calculator.git`

## Step 7: Add Build Step

- Execute Shell:

```bash
python3 calculator.py
```

## Step 8: Build Now

Expected output:

```
Addition = 30
Subtraction = 10
Multiplication = 200
Division = 2.0
```

**Debug:**

| Error | Fix |
|---|---|
| `python3: command not found` | `sudo apt install python3 -y` |
| Jenkins cannot clone repo | Verify Repository URL, branch name, internet connection, and `git --version` |

---

---

# PROGRAM 9 — Java Reverse Number + GitHub + Jenkins

---

## Step 1: Create Project

```bash
mkdir java-reverse
cd java-reverse
```

## Step 2: Create Program

```bash
nano Reverse.java
```

```java
public class Reverse {
    public static void main(String[] args) {

        int num = 12345;
        int rev = 0;

        while(num != 0) {
            rev = rev * 10 + num % 10;
            num = num / 10;
        }

        System.out.println("Reverse = " + rev);
    }
}
```

## Step 3: Test Program

```bash
javac Reverse.java
java Reverse
```

Expected output: `Reverse = 54321`

## Step 4: Push to GitHub

```bash
git init
git add .
git commit -m "Java Reverse Program"
git branch -M main
git remote add origin https://github.com/USERNAME/java-reverse.git
git push -u origin main
```

## Step 5: Create Jenkins Job

- New Item → Name: `Java-Reverse` → Freestyle Project
- SCM → Git → Repository: `https://github.com/USERNAME/java-reverse.git`
- Build Step → Execute Shell:

```bash
javac Reverse.java
java Reverse
```

- Build Now → Expected: `Reverse = 54321`

---

---

# PROGRAM 10 — Run Hello World Docker Image + Jenkins Scheduled Job

---

## Part A: Run Hello World Docker Image

```bash
docker pull hello-world
docker images
docker run hello-world
```

Expected: `Hello from Docker!`

**Debug — Docker service not running:** `sudo systemctl start docker`

---

## Part B: Jenkins Scheduled Job

### Create Job

- New Item → Name: `HelloWorldJob` → Freestyle Project
- Build Step → Execute Shell:

```bash
date
hostname
whoami
pwd
```

### Configure Periodic Build

- Build Triggers → Build periodically
- Schedule: `* * * * *` (runs every minute)

### Build Now

- Click Build Now → Check Console Output

---

---

# PROGRAM 11 — HTML Registration Form + Jenkins HTML Publisher

---

## Step 1: Create Project

```bash
mkdir registration-form
cd registration-form
```

## Step 2: Create HTML

```bash
nano index.html
```

```html
<!DOCTYPE html>
<html>
<head>
  <title>Registration Form</title>
</head>
<body>

<h2>Student Registration</h2>

<form>
  Name:<br>
  <input type="text"><br><br>

  Email:<br>
  <input type="email"><br><br>

  Password:<br>
  <input type="password"><br><br>

  <input type="submit">
</form>

</body>
</html>
```

## Step 3: Test Locally

```bash
xdg-open index.html
```

## Step 4: Push to GitHub

```bash
git init
git add .
git commit -m "Registration Form"
git branch -M main
git remote add origin https://github.com/USERNAME/registration-form.git
git push -u origin main
```

## Step 5: Install HTML Publisher Plugin

Jenkins → Manage Jenkins → Plugins → Search: `HTML Publisher Plugin` → Install

## Step 6: Create Jenkins Job

- New Item → Name: `HTML-Publisher` → Freestyle Project
- SCM → Git → Repository: `https://github.com/USERNAME/registration-form.git`
- Post Build Action → Publish HTML Reports:
  - HTML Directory: `.`
  - Index Page: `index.html`
  - Report Title: `Registration Form`

- Build → HTML page available through Jenkins

---

---

# PROGRAM 12 — Jenkins Pipeline Using Jenkinsfile (SCM Git)

---

## Step 1: Create Project

```bash
mkdir pipeline-demo
cd pipeline-demo
```

## Step 2: Create Jenkinsfile

```bash
nano Jenkinsfile
```

```groovy
pipeline {

    agent any

    stages {

        stage('Build') {
            steps {
                echo 'Building'
            }
        }

        stage('Test') {
            steps {
                echo 'Testing'
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploying'
            }
        }
    }
}
```

## Step 3: Push to GitHub

```bash
git init
git add .
git commit -m "Pipeline"
git branch -M main
git remote add origin https://github.com/USERNAME/pipeline-demo.git
git push -u origin main
```

## Step 4: Create Jenkins Pipeline Job

- New Item → Name: `PipelineDemo` → Pipeline
- Pipeline Definition: `Pipeline script from SCM`
- SCM: Git
- Repository: `https://github.com/USERNAME/pipeline-demo.git`
- Script Path: `Jenkinsfile`
- Build Now

Expected stages: `Build → Test → Deploy` (visible visually)

---

---

# PROGRAM 13 — Pattern Programs (Java + Python) + File Parameterization

---

## Java Pattern

```bash
nano Pattern.java
```

```java
public class Pattern {
    public static void main(String args[]) {

        for(int i=1; i<=5; i++) {
            for(int j=1; j<=i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
```

Expected output:

```
*
* *
* * *
* * * *
* * * * *
```

## Python Pattern

```bash
nano pattern.py
```

```python
for i in range(1, 6):
    for j in range(i):
        print("*", end=" ")
    print()
```

## Push Both Files

```bash
git init
git add .
git commit -m "Pattern Programs"
git branch -M main
git remote add origin https://github.com/USERNAME/pattern-programs.git
git push -u origin main
```

## Jenkins File Parameterization

- Job → Name: `PatternJob`
- Enable: `This project is parameterized`
- Choose: `File Parameter`
- Parameter Name: `INPUTFILE`
- Build Step → Execute Shell:

```bash
javac Pattern.java
java Pattern
python3 pattern.py
```

---

---

# PROGRAM 14 — Ubuntu Docker Container + Jenkins Pipeline With 5 Stages

---

## Part A: Run Ubuntu Container Named MyContainer

```bash
docker pull ubuntu
docker run -it --name MyContainer ubuntu
```

Inside container:

```bash
pwd
ls
whoami
date
hostname
exit
```

Verify:

```bash
docker ps -a
```

Start again:

```bash
docker start MyContainer
docker attach MyContainer
```

**Debug — Container exited:** `docker start MyContainer`

---

## Part B: Jenkins Pipeline With 5 Stages

```bash
nano Jenkinsfile
```

```groovy
pipeline {

    agent any

    stages {

        stage('Checkout') {
            steps {
                echo 'Checkout Stage'
            }
        }

        stage('Build') {
            steps {
                echo 'Build Stage'
            }
        }

        stage('Test') {
            steps {
                echo 'Test Stage'
            }
        }

        stage('Package') {
            steps {
                echo 'Package Stage'
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploy Stage'
            }
        }
    }
}
```

Push to GitHub:

```bash
git init
git add .
git commit -m "5 Stage Pipeline"
git branch -M main
git remote add origin https://github.com/USERNAME/pipeline-5-stage.git
git push -u origin main
```

Create Jenkins Pipeline Job:

- Name: `Pipeline5Stage`
- Pipeline Script From SCM → Git
- Repository: `https://github.com/USERNAME/pipeline-5-stage.git`
- Script Path: `Jenkinsfile`
- Build Now

Expected stages: `Checkout → Build → Test → Package → Deploy`

---

---

# PROGRAM 15 — Run Python Docker Image + Kubernetes Nginx Deployment

---

## Part A: Run Python Docker Image

```bash
docker pull python:3.11
docker images
docker run -it --name PythonContainer python:3.11 bash
```

Inside container:

```bash
python --version
python
```

Inside Python interpreter:

```python
print("Hello DevOps")
exit()
```

Other commands:

```bash
pwd
ls
whoami
exit
```

---

## Part B: Kubernetes Nginx Deployment

```bash
kubectl create deployment nginx-deployment --image=nginx
kubectl get deployments
kubectl get pods
kubectl describe deployment nginx-deployment
kubectl scale deployment nginx-deployment --replicas=3
kubectl get pods
kubectl delete deployment nginx-deployment
```

---

---

# PROGRAM 16 — Run Node Docker Image + Kubernetes Python Deployment

---

## Part A: Run Node Container

```bash
docker pull node:20
docker run -it --name NodeContainer node:20 bash
```

Inside container:

```bash
node -v
npm -v
node
```

Inside Node REPL:

```javascript
console.log("Hello DevOps");
.exit
```

Exit container:

```bash
exit
```

---

## Part B: Kubernetes Python Deployment

```bash
kubectl create deployment python-deployment --image=python:3.11
kubectl get deployments
kubectl get pods
kubectl describe deployment python-deployment
kubectl scale deployment python-deployment --replicas=2
kubectl delete deployment python-deployment
```

---

---

# PROGRAM 17 — Run Nginx Docker Image + Kubernetes Mongo Deployment

---

## Part A: Run Nginx Docker Image

```bash
docker pull nginx
docker run -d --name nginxContainer -p 8080:80 nginx
docker ps
```

Open: `http://localhost:8080` (Nginx welcome page appears)

Enter container:

```bash
docker exec -it nginxContainer bash
```

Inside container:

```bash
pwd
ls
hostname
exit
```

Stop container:

```bash
docker stop nginxContainer
```

---

## Part B: Kubernetes Mongo Deployment

```bash
kubectl create deployment mongo-deployment --image=mongo
kubectl get deployments
kubectl get pods
kubectl describe deployment mongo-deployment
kubectl scale deployment mongo-deployment --replicas=2
kubectl delete deployment mongo-deployment
```

---

---

# PROGRAM 18 — Containerized HTML Registration Form + DockerHub + GitHub

---

## Step 1: Create Folder

```bash
mkdir registration-docker
cd registration-docker
```

## Step 2: Create HTML

```bash
nano index.html
```

```html
<!DOCTYPE html>
<html>
<head>
  <title>Registration Form</title>
</head>
<body>

<h2>Student Registration</h2>

<form>
  Name: <input type="text"><br><br>
  Email: <input type="email"><br><br>
  Password: <input type="password"><br><br>
  <input type="submit">
</form>

</body>
</html>
```

## Step 3: Create Dockerfile

```bash
nano Dockerfile
```

```dockerfile
FROM nginx:latest
COPY index.html /usr/share/nginx/html/index.html
```

## Step 4: Build and Run

```bash
docker build -t registration-form .
docker run -d -p 8080:80 registration-form
```

Open: `http://localhost:8080` (Registration form appears)

## Step 5: Push to GitHub

```bash
git init
git add .
git commit -m "Registration Form"
git branch -M main
git remote add origin https://github.com/USERNAME/registration-form.git
git push -u origin main
```

## Step 6: Push to DockerHub

```bash
docker login
docker tag registration-form USERNAME/registration-form:v1
docker push USERNAME/registration-form:v1
```

---

---

# PROGRAM 19 — Docker Compose BusyBox Communication

---

## Step 1: Install Docker Compose

```bash
docker compose version
```

If not installed:

```bash
sudo apt install docker-compose -y
```

## Step 2: Create Folder

```bash
mkdir busybox-compose
cd busybox-compose
```

## Step 3: Create docker-compose.yml

```bash
nano docker-compose.yml
```

```yaml
services:

  bbConA:
    image: busybox
    container_name: bbConA
    tty: true

  bbConB:
    image: busybox
    container_name: bbConB
    tty: true
```

## Step 4: Start Containers

```bash
docker compose up -d
docker ps
```

## Step 5: Enter Container A and Ping Container B

```bash
docker exec -it bbConA sh
ping bbConB
```

Expected: `64 bytes from bbConB`

Exit and stop:

```bash
exit
docker compose down
```

---

---

# PROGRAM 20 — Kubernetes Nginx Deployment Using YAML

---

## Step 1: Create YAML File

```bash
nano nginx-deployment.yaml
```

```yaml
apiVersion: apps/v1

kind: Deployment

metadata:
  name: nginx-deployment

spec:
  replicas: 2

  selector:
    matchLabels:
      app: nginx

  template:

    metadata:
      labels:
        app: nginx

    spec:
      containers:
      - name: nginx
        image: nginx
        ports:
        - containerPort: 80
```

## Step 2: Apply Deployment

```bash
kubectl apply -f nginx-deployment.yaml
kubectl get deployments
kubectl get pods
kubectl describe deployment nginx-deployment
```

## Step 3: Scale Replicas

Edit `nginx-deployment.yaml` — change `replicas: 2` to `replicas: 4`, then:

```bash
kubectl apply -f nginx-deployment.yaml
kubectl get pods
```

Should show 4 pods.

## Step 4: Delete Deployment

```bash
kubectl delete -f nginx-deployment.yaml
```

---

### Viva Questions (Programs 15–20)

| Question | Answer |
|---|---|
| Difference between Docker and Kubernetes? | Docker = Containerization; Kubernetes = Orchestration |
| What is a Pod? | Smallest deployable unit in Kubernetes |
| What is a Deployment? | Manages Pods and ReplicaSets |
| What is a Replica? | Additional copies of Pods for availability |
| `kubectl create` vs `kubectl apply`? | `create` = new resource; `apply` = create or update |
| What is Docker Compose? | Tool to manage multiple containers using a single YAML file |

---

---

# PROGRAM 21 — Kubernetes Node Deployment + Selenium Open Website

---

## Part A: Kubernetes Node Deployment

```bash
kubectl create deployment node-deployment --image=node:20
kubectl get deployments
kubectl get pods
kubectl describe deployment node-deployment
kubectl scale deployment node-deployment --replicas=3
kubectl get pods
kubectl delete deployment node-deployment
```

---

## Part B: Selenium JavaScript — Open Website

### Install Chrome

```bash
sudo apt update
sudo apt install google-chrome-stable -y
```

### Create Project

```bash
mkdir selenium-open-site
cd selenium-open-site
npm init -y
npm install selenium-webdriver
```

### Create openGoogle.js

```bash
nano openGoogle.js
```

```javascript
const {Builder} = require("selenium-webdriver");

async function test() {
    let driver = await new Builder().forBrowser('chrome').build();
    await driver.get("https://www.google.com");
    await driver.sleep(5000);
    await driver.quit();
}

test();
```

Run:

```bash
node openGoogle.js
```

Browser opens Google automatically.

---

---

# PROGRAM 22 — Login Validation Application + Selenium

---

## Step 1: Create Login HTML

```bash
nano login.html
```

```html
<!DOCTYPE html>
<html>
<body>

  Username: <input id="user">
  Password: <input id="pass">
  <button onclick="validate()">Login</button>
  <p id="msg"></p>

  <script>
  function validate(){
      let u = document.getElementById("user").value;
      let p = document.getElementById("pass").value;

      if(u === "admin" && p === "admin123")
          document.getElementById("msg").innerHTML = "Login Success";
      else
          document.getElementById("msg").innerHTML = "Login Failed";
  }
  </script>

</body>
</html>
```

## Step 2: Create Selenium Test

```bash
nano loginTest.js
```

```javascript
const {Builder, By} = require("selenium-webdriver");

async function run(){
    let driver = await new Builder().forBrowser("chrome").build();

    await driver.get("file:///FULL_PATH/login.html");

    await driver.findElement(By.id("user")).sendKeys("admin");
    await driver.findElement(By.id("pass")).sendKeys("admin123");
    await driver.findElement(By.tagName("button")).click();

    await driver.sleep(3000);
    await driver.quit();
}

run();
```

Run:

```bash
node loginTest.js
```

---

---

# PROGRAM 23 — Check Exam Result Website Using Selenium

---

```bash
nano resultCheck.js
```

```javascript
const {Builder} = require("selenium-webdriver");

async function run(){
    let driver = await new Builder().forBrowser("chrome").build();
    await driver.get("https://matrusri.skolo.in/");
    await driver.sleep(10000);
    await driver.quit();
}

run();
```

Run:

```bash
node resultCheck.js
```

**External Exam Tip:** If examiner asks for result search, locate the textbox and button using:

```javascript
By.id()
By.name()
By.xpath()
```

---

---

# PROGRAM 24 — Calculator Web App + Selenium Testing

---

## Step 1: Create Calculator HTML

```bash
nano calculator.html
```

```html
<!DOCTYPE html>
<html>
<body>

  <input id="a">
  <input id="b">
  <button onclick="add()">Add</button>
  <p id="result"></p>

  <script>
  function add(){
      let a = parseInt(document.getElementById("a").value);
      let b = parseInt(document.getElementById("b").value);
      document.getElementById("result").innerHTML = a + b;
  }
  </script>

</body>
</html>
```

## Step 2: Create Selenium Test

```bash
nano calculatorTest.js
```

```javascript
const {Builder, By} = require("selenium-webdriver");

async function run(){
    let driver = await new Builder().forBrowser("chrome").build();

    await driver.get("file:///FULL_PATH/calculator.html");

    await driver.findElement(By.id("a")).sendKeys("10");
    await driver.findElement(By.id("b")).sendKeys("20");
    await driver.findElement(By.tagName("button")).click();

    await driver.sleep(3000);
    await driver.quit();
}

run();
```

Run:

```bash
node calculatorTest.js
```

---

---

# PROGRAM 25 — Jenkins Remote Trigger Build

---

## Step 1: Create Java Program

```bash
nano Hello.java
```

```java
public class Hello {
    public static void main(String args[]){
        System.out.println("Hello Jenkins");
    }
}
```

## Step 2: Push to GitHub

```bash
git init
git add .
git commit -m "Java Jenkins"
git branch -M main
git remote add origin https://github.com/USERNAME/java-jenkins.git
git push -u origin main
```

## Step 3: Create Jenkins Job

- New Item → Name: `JavaRemoteBuild` → Freestyle Project
- Configure Git Repository
- Build Step → Execute Shell:

```bash
javac Hello.java
java Hello
```

## Step 4: Enable Remote Trigger

- Build Triggers → Trigger builds remotely
- Authentication Token: `build123`

## Step 5: Trigger via URL

```bash
curl http://localhost:8080/job/JavaRemoteBuild/build?token=build123
```

Or open in browser: `http://localhost:8080/job/JavaRemoteBuild/build?token=build123`

---

---

# PROGRAM 26 — Jenkins SCM Polling

---

## Step 1: Create Python Calculator

```bash
nano calculator.py
```

```python
a = 20
b = 10

print("Add =", a+b)
print("Sub =", a-b)
print("Mul =", a*b)
print("Div =", a/b)
```

## Step 2: Push to GitHub

```bash
git init
git add .
git commit -m "Calculator"
git branch -M main
git remote add origin https://github.com/USERNAME/python-calculator.git
git push -u origin main
```

## Step 3: Create Jenkins Job

- New Item → Name: `PythonCalculatorPolling` → Freestyle Project
- Git Repository: `https://github.com/USERNAME/python-calculator.git`
- Build Step → Execute Shell:

```bash
python3 calculator.py
```

## Step 4: Enable SCM Polling

- Build Triggers → Poll SCM
- Schedule: `* * * * *` (checks GitHub every minute)

## Step 5: Test Auto-Build

Modify the file:

```python
print("SCM Polling Demo")
```

Push:

```bash
git add .
git commit -m "Updated"
git push
```

Jenkins automatically detects changes and triggers a build.

---

---

# PROGRAM 27 — Java + Python Calculator + File and Variable Parameterization

---

## Step 1: Create Java Calculator

```bash
nano Calculator.java
```

```java
public class Calculator {

    public static void main(String args[]){

        int a = 20;
        int b = 10;

        System.out.println("Add=" + (a+b));
        System.out.println("Sub=" + (a-b));
        System.out.println("Mul=" + (a*b));
        System.out.println("Div=" + (a/b));
    }
}
```

## Step 2: Create Python Calculator

```bash
nano calculator.py
```

```python
a = 20
b = 10

print("Add =", a+b)
print("Sub =", a-b)
print("Mul =", a*b)
print("Div =", a/b)
```

## Step 3: Push Both Files to GitHub

```bash
git init
git add .
git commit -m "Parameterized Calculator"
git branch -M main
git remote add origin https://github.com/USERNAME/calculator-parameterized.git
git push -u origin main
```

## Step 4: Create Jenkins Job

- New Item → Name: `CalculatorParameterized` → Freestyle Project
- Enable: `This project is parameterized`

### Add String Parameter — NUM1

- Name: `NUM1`
- Default: `20`

### Add String Parameter — NUM2

- Name: `NUM2`
- Default: `10`

### Add File Parameter

- Name: `INPUTFILE`

## Step 5: Build Step

- Execute Shell:

```bash
echo "Num1 = $NUM1"
echo "Num2 = $NUM2"
python3 calculator.py
javac Calculator.java
java Calculator
```

## Step 6: Build With Parameters

- Click: `Build With Parameters`
- Enter `NUM1 = 100`, `NUM2 = 50`
- Build

---

---

# Common Viva Questions (Programs 21–27)

| Question | Answer |
|---|---|
| What is Selenium? | Automation tool for browser testing |
| What is WebDriver? | API that controls browser actions |
| What is Jenkins? | Open-source CI/CD automation server |
| Freestyle vs Pipeline? | Freestyle = GUI-based; Pipeline = Code-based (Jenkinsfile) |
| What is SCM Polling? | Jenkins periodically checks Git for changes and auto-builds |
| What is Remote Trigger? | Allows job execution through a URL or API |
| What is Parameterization? | Passing user inputs to Jenkins jobs during execution |
| What is CI/CD? | CI = Continuous Integration; CD = Continuous Delivery/Deployment |

---

*End of DevOps Lab — All 27 Programs*
