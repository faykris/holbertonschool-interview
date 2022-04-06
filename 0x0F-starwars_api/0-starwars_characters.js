#!/usr/bin/node

const request = require('request');
const dict = [];
let i = 0;
request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], (ferr, fresponse, fbody) => {
  if (ferr) return console.log(ferr);
  for (const chr of JSON.parse(fbody).characters) {
    request(chr, (cerr, cresponse, cbody) => {
      if (cerr) return console.log(cerr);
      const character = JSON.parse(cbody);
      const words = chr.split('/');
      const id = words[5];
      if (!dict[id]) {
        dict[id] = [];
      }
      dict[id].push(character.name);
      if (i === JSON.parse(fbody).characters.length - 1) {
        for (const ele of dict) if (ele) console.log(ele[0]);
      }
      i++;
    });
  }
});
