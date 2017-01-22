all: zones.h

UTZ_DATA_DIR = vendor/tzdata
UTZ_REGIONS = africa,asia,australasia,backward,europe,northamerica,pacificnew,southamerica
UTZ_WHITELIST = whitelist.txt
UTZ_INCLUDES = majormetros
export UTZ_DATA_DIR:=$(UTZ_DATA_DIR)
export UTZ_REGIONS:=$(UTZ_REGIONS)
export UTZ_INCLUDES:=$(UTZ_INCLUDES)

zones.h: $(UTZ_DATA_DIR) $(UTZ_INCLUDES) $(UTZ_WHITELIST) utils/generate_zones.py utils/utz.py
	./utils/generate_zones.py

whitelist.txt: vendor/android/timezones.xml majormetros utils/compile_whitelist.py 
	./utils/compile_whitelist.py

# The IANA timezone database is missing zone links for many of the worlds largest metropolitan areas
majormetros:
	./utils/compile_tzlinks.py

clean:
	rm zones.h
