FROM bash:latest

RUN ["mkdir", "-p", "/usr/src/app/"]
WORKDIR /usr/src/app/

COPY ./Docker/ /usr/src/app/
COPY ./Scripts/ /usr/src/app/

RUN ["chmod", "+x", "run_scripts.sh", "all_file_dir.sh", "file_type.sh", "line_count.sh", "num_rev.sh"]
CMD ["./run_scripts.sh"]
