public class Banner {
    private Integer id;
    private String link;
    private String type;
    private byte[] file;

    public void setId(Integer id) {
        this.id = id;
    }
    public Integer getId() {
        return id;
    }
    public void setLink(String link) {
        this.link = link;
    }
    public String getLink() {
        return link;
    }
    public void setType(String type) {
        this.type = type;
    }
    public String getType() {
        return type;
    }
    public void setFile(byte[] file) {
        this.file = file;
    }
    public byte[] getFile() {
        return file;
    }
}
