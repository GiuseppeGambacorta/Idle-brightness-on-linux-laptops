<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
<div style="text-align:center;">

[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]
</div>



<!-- PROJECT LOGO -->
<br />


<h3 align="center">Idle brightness for linux laptops</h3>
  
</div>







<!-- ABOUT THE PROJECT -->
## About The Project

I've developed a small program to effectively manage my laptop's screen brightness during periods of inactivity. Since I don't usually lock the screen, I've designed the program to automatically reduce the screen's energy consumption when I step away from the computer for a while.
Currently work only on X11 on POP OS.

<p align="right">(<a href="#readme-top">back to top</a>)</p>





<!-- GETTING STARTED -->
## Getting Started
- install the library
```
sudo apt-get install libx11-dev
```
- check the path of you brightness values on you laptops, i don't know if is always the same path
- Adjust the duration after which the screen dims
- compile the program with:
```
gcc main.c -o brightness -lX11 -lXss
```
- change brightness.sh with you executable file path
- add to visudo the executable
```
sudo visudo
```
- add this at the end of the file
```
<username> ALL=(ALL) NOPASSWD: <path of the executable>/brightness
```
- now add a service in user systemctl, so it will start like a background service, you will find an example in the repo, "brightness.service", of course change the path to you brightness.sh
```
/etc/systemd/user
```
- now reload systemctl daemon and start the service
```
systemctl --user daemon-reload
systemctl --user start brightness.service

```
- check if it is working with
```
systemctl --user status brightness.service
```
- final step, on gnome i added the systemctl start comand at the start-up of gnome, this is a workaround for problems with X11 and privileges. we are not enabling from systemct --user enable comand

```
gnome-session-properties
```
- restart the laptop and check with the status comand if it is working






<!-- ROADMAP -->
## Roadmap

- [ ] Add a config file for brightness path and idle times


See the [open issues](https://github.com/GiuseppeGambacorta/PLC-Standard-IEC-61131-3-for-Arduino/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Gambacorta Giuseppe -  - gambacortagiuseppe@outlook.it

Project Link: [https://github.com/GiuseppeGambacorta/Idle-brightness-on-linux-laptops
](https://github.com/GiuseppeGambacorta/Idle-brightness-on-linux-laptops
)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



[license-shield]: https://img.shields.io/github/license/GiuseppeGambacorta/PLC-Standard-IEC-61131-3-for-Arduino.svg?style=for-the-badge
[license-url]: https://github.com/GiuseppeGambacorta/PLC-Standard-IEC-61131-3-for-Arduino/blob/main/LICENSE.TXT


[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/giuseppe-gambacorta-36534425a/






