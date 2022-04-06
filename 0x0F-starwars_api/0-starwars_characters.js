#!/usr/bin/node

const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], (ferr, fresponse, fbody) => {
  if (ferr) return console.log(ferr);
  for (const chr of JSON.parse(fbody).characters) {
    request(chr, (cerr, cresponse, cbody) => {
      if (cerr) return console.log(cerr);
      console.log(JSON.parse(cbody).name);
    });
  }
});
