explain analyze SELECT star.ra FROM star WHERE star.modelmag_r > 0 and star.modelmag_r < 21 and star.ra < 205.446972452536 and star.ra > 203.2108728477 and star.dec > 9.860958219299748 and star.dec < 11.62881354954442 order by star.modelmag_r limit 999;