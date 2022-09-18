type Obj = {
	[key: string]: {
		capital: string;
		population: number;
		languages: string[];
	};
};

let obj1: Obj = {
	bangladesh: {
		capital: 'dhaka',
		population: 160000000,
		languages: ['bengali', 'english']
	},
	india: {
		capital: 'delhi',
		population: 1300000000,
		languages: ['hindi', 'english']
	},
	pakistan: {
		capital: 'islamabad',
		population: 200000000,
		languages: ['urdu', 'english']
	}
};

Object.keys(obj1).map((key) => {
	console.log(`country: ${key}`);
	console.log(`capital: ${obj1[key].capital}`);
	console.log(`population: ${obj1[key].population}`);
	obj1[key].languages.map((lang) => {
		console.log(`language: ${lang}`);
	});
});
