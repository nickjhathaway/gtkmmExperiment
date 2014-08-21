#!/bin/bash

recreateDir()(
	for x in $(find $1 -type d); do
		mkdir -p $(echo "${x}" | sed "s/${1//\//\/}/${2//\//\/}/g" ) ;
	done	
)

recreateDir $1 $2

for x in $(gfind $1 -iregex '.*\(\.h\|\.hpp\)'); do 
	cp ${x} $(echo "${x}" | sed "s/${1//\//\/}/${2//\//\/}/g" ) ;
done 

