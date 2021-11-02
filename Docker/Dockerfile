FROM bash:latest

RUN ["mkdir", "-p", "/usr/src/app/"]
WORKDIR /usr/src/app/

COPY . /usr/src/app/

RUN ["chmod", "+x", "all_file_dir.sh", "file_type.sh", "line_count.sh", "num_rev.sh"]
CMD ["./run_scripts.sh"]
