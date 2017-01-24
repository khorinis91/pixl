#!/usr/bin/env python3

#
# Copyright (c) 2017 Marcus Brummer.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

import pixl
import sys
import os
from os import path

def is_image(file_name):
	lower = file_name.lower()
	return lower.endswith('.jpg') or lower.endswith('.jpeg') or lower.endswith('png')

def resize_image(file, output):
	output_path = file.split('/')[-1:][0]
	output_path = path.join(output, output_path)

	image = pixl.Image(file)
	width = image.width() * 0.2
	height = image.height() * 0.2
	pixl.resize(image, width, height)
	pixl.save_image(output_path, image)

	image.destroy()


def create_thumbnails(folder):
	# create output folder
	thumb_dir = path.join(folder, 'thumbs/')
	if not path.exists(thumb_dir):
		os.mkdir(thumb_dir)

	# create thumbnails
	for file in [path.join(folder, f) for f in os.listdir(folder)]:
		if path.isfile(file) and is_image(file):
			resize_image(file, thumb_dir)
			print('Created thumbnail for', file)


if __name__ == "__main__":
	if len(sys.argv) == 2:
		create_thumbnails(sys.argv[1])
	else:
		print("Usage: ./thumb.py folder")