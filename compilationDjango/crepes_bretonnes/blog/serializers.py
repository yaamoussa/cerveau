from rest_framework import serializers
from blog.models  import Articles



class ArticlemodelSerializer(serializers.ModelSerializer):


	class Meta:
		model=Articles
		fields=('titre','auteur')