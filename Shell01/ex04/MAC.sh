ifconfig | grep "ether " | sed 's/ether/ /' | tr -d '[:blank:]'
