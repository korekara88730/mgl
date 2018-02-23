#coding=utf-8

import sys;
import json;

'''
x,y,z
'''
vertice = [];

'''
u,v
'''
uvs = [];

'''
x,y,z
'''
normals = [];

'''
faces{
	Temp ignore mtl,only hold vertice
	[
		{
			vertice x 3:[
				{
					vertex:verticeIndex,
					uv:uvIndex,
					normal:normalIndex,
				},
				{
					vertex:verticeIndex,
					uv:uvIndex,
					normal:normalIndex,
				},
				{
					vertex:verticeIndex,
					uv:uvIndex,
					normal:normalIndex,
				}
			]
		}	
	]
}
'''
faces = [];

def handleLine(line):
	global vertice
	global uvs
	global normals
	global faces

	
	if line.find("v ") == 0:
		# vertice
		line.replace("\n","");
		arr = line.split(" ");
		info = {};
		info["x"] = float(arr[1]);
		info["y"] = float(arr[2]);
		info["z"] = float(arr[3]);
		vertice.append(info);
	elif line.find("vt ") == 0:
		# uvs
		line.replace("\n","");
		arr = line.split(" ");
		info = {};
		info["u"] = float(arr[1]);
		info["v"] = float(arr[2]);
		uvs.append(info);
	elif line.find("vn ") == 0:
		# normals
		line.replace("\n","");
		arr = line.split(" ");
		info = {};
		info["x"] = float(arr[1]);
		info["y"] = float(arr[2]);
		info["z"] = float(arr[3]);
		normals.append(info);
	elif line.find("f ") == 0:
		# faces
		line.replace("\n","");
		arr = line.split(" ");
		faceInfo = [];
		for index in range(1,4):
			# 127/997/997
			wholeInfo = arr[index];
			vinfo = wholeInfo.split("/");
			detail = {}
			detail["vertexIndex"] = int(vinfo[0]);
			detail["uvIndex"] = int(vinfo[1]);
			detail["normalIndex"] = int(vinfo[2]);
			faceInfo.append(detail);
		# if len(faces) <= 2:
		faces.append(faceInfo);

def exportJson(filePath):
	global vertice;
	global uvs;
	global normals;
	global faces;

	modelInfo = {};
	modelInfo["vertice"] = vertice;
	modelInfo["uvs"] = uvs;
	modelInfo["normals"] = normals;
	modelInfo["faces"] = faces;

	strJson = json.dumps(modelInfo);

	outName = filePath + ".json"
	jsonFile = open(outName,"w");
	jsonFile.write(strJson);
	jsonFile.close();


def startJob(filePath):
	print("Obj File:" + filePath);
	file = open(filePath,"r");
	for line in file.readlines():
		#print(line);
		handleLine(line);
	file.close();
	exportJson(filePath);
	
if __name__ == '__main__':
	if len(sys.argv) < 2:
		print("Must has 1 arg which is obj file name.");
	else:
		filePath = sys.argv[1];
		startJob(filePath);
	