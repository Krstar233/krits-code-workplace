package mongodb;

import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.result.DeleteResult;
import org.bson.Document;

import java.util.Arrays;

import static com.mongodb.client.model.Filters.*;

public class JDBCTest {
    public static void main(String[] args) {
        try{
            // 连接到 mongodb 服务
            MongoClient mongoClient = MongoClients.create();
            System.out.println("Connect to database successfully");
            // 连接到数据库
            MongoDatabase database = mongoClient.getDatabase("runoob");
            MongoCollection<Document> collection = database.getCollection("col");
            Document doc = new Document("name", "MongoDB")
                    .append("type", "database")
                    .append("count", 1)
                    .append("versions", Arrays.asList("v3.2", "v3.0", "v2.6"))
                    .append("info", new Document("x", 203).append("y", 102));
            System.out.println(doc.toJson());
            collection.insertOne(doc);
            Document myDoc = collection.find(eq("type","database")).first();
            System.out.println(myDoc.toJson());
            DeleteResult deleteResult = collection.deleteMany(gte("type","database"));
            System.out.println(deleteResult.getDeletedCount());
        }catch(Exception e){
            System.err.println( e.getClass().getName() + ": " + e.getMessage() );
        }
    }
}
