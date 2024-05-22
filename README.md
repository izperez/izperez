### Hi there 👋

<!--
**izperez/izperez** is a ✨ _special_ ✨ repository because its `README.md` (this file) appears on your GitHub profile.

Here are some ideas to get you started:

- 🔭 I’m currently working on ...
- 🌱 I’m currently learning in 42 Urduliz
- 👯 I’m looking to collaborate on ...
- 🤔 I’m looking for help with ...
- 💬 Ask me about ...
- 📫 How to reach me: ...
- 😄 Pronouns: ...
- ⚡ Fun fact: ...
-->
[![Anurag's GitHub stats](https://github-readme-stats.vercel.app/api?username=izperez)](https://github.com/anuraghazra/github-readme-stats)

const { Contributions } = require('contributions')

const contributions = await Contributions.forUser('ethomson');
const days = contributions.getDays();

for (let day of days) {
    console.log(`${day.getDate()}: ${day.getIntensity()}`);
}
