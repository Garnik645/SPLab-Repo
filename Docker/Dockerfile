FROM bash:latest

RUN ["mkdir", "-p", "/usr/src/app/"]
WORKDIR /usr/src/app/
RUN ["mkdir", "-p", "Docker"]
RUN ["mkdir", "-p", "Scripts"]

COPY ./Docker/ /usr/src/app/Docker/
COPY ./Scripts/ /usr/src/app/Scripts/

WORKDIR /usr/src/app/Scripts/
RUN ["chmod", "+x", "all_file_dir.sh", "file_type.sh", "line_count.sh", "num_rev.sh"]

WORKDIR /usr/src/app/Docker/
RUN ["chmod", "+x", "run_scripts.sh"]
CMD ["./run_scripts.sh"]
