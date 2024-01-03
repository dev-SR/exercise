import fs from 'fs';
// import fs from 'fs-extra';

import path from 'path';
export const runCopyFn = () => {
	const to_copy_path = path.join(process.cwd(), '04_io', 'to_copy');
	const copied_path = path.join(process.cwd(), '04_io', 'copied');
	// delete existing copied directory
	if (fs.existsSync(copied_path)) {
		fs.rmdirSync(copied_path, { recursive: true });
	}
	// create new copied directory
	fs.mkdirSync(copied_path);
	// copy files from to_copy directory to copied directory
	fs.cpSync(to_copy_path.toString(), copied_path.toString(), {
		recursive: true,
		errorOnExist: false,
		filter: (src, dest) => {
			return !src.includes('node_modules');
		}
	});
};
